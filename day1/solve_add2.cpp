#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char** argv) {

    if (argc < 2) {
        cout << "no argument" << endl;
        return 0;
    }
    
    string filename = argv[1];
    ifstream file (filename);
    string line;
    vector<int> array (2021, 0);
    

    if (file.is_open()) {
        while (getline(file, line)) {
            int i = stoi(line);
            if (array[2020-i]) {
                cout << "i:" << i << "  j:" << 2020 - i << "  answer:" << i*(2020-i) <<  endl;
            } else {
                ++array[i];
            }
        }
        file.close();
    } else {
        cout << "unable to open file" << endl;
    }

    return 0;
}
