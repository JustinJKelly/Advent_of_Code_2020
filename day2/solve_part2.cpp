#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {

    if (argc < 2) {
        cout << "no argument" << endl;
        return 0;
    }
    
    string filename = argv[1];
    ifstream file (filename);
    string line;
    int count_valid = 0;

    string delimiter_1 = "-";
    string delimiter_2 = " ";
    string delimiter_3 = ":";

    if (file.is_open()) {
        while (getline(file, line)) {
            string minimum = line.substr(0, line.find(delimiter_1));
            string alt_line = line.substr(line.find(delimiter_1)+1);
            
            string maximum = alt_line.substr(0, alt_line.find(delimiter_2));
            alt_line = alt_line.substr(alt_line.find(delimiter_2)+1);

            string letter = alt_line.substr(0, alt_line.find(delimiter_3));
            alt_line = alt_line.substr(alt_line.find(delimiter_3)+2);
            //cout << minimum << " " << maximum << " " << letter << " " << line << endl;

            int found = alt_line[stoi(maximum)-1] == letter[0];
            int found2 = alt_line[stoi(minimum)-1] == letter[0];
            if (!found != !found2) {
                //cout << letter << " " << alt_line << "  " << line << endl;
                ++count_valid;
            }
        }
        file.close();
    } else {
        cout << "unable to open file" << endl;
    }
    cout << "answer:" << count_valid << endl;

    return 0;
}
