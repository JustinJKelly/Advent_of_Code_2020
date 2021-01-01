#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int count_letters(char letter, string line) {
    int count_errors = 0;
    for (int i = 0; i < line.size(); ++i)
        if (line[i] == letter) ++count_errors; 

    return count_errors;
}

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

            //int count_num_occurrences = count_letters(letter[0], alt_line);

            int count_num_occurrences = count(alt_line.begin(),alt_line.end(), letter[0]); 
            if (!(count_num_occurrences < stoi(minimum) || count_num_occurrences > stoi(maximum))) {
                //cout << alt_line << endl;
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
