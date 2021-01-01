#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

int main(int argc, char** argv) {

    if (argc < 2) {
        cout << "no argument" << endl;
        return 0;
    }
    
    string filename = argv[1];
    ifstream file (filename);
    string line;
    int count_people = 0, count = 0;
    unordered_map<char, int> m;
 
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line != "") {
                for (char ch: line) ++m[ch];
                ++count_people;
            } else {
                for (auto it: m) {
                    if (it.second == count_people) ++count;
                }
                m.clear();
                count_people = 0;
            }   
        }
        file.close();
    } else {
        cout << "unable to open file" << endl;
    }

    for (auto it: m) {
        if (it.second == count_people) ++count;
    }
 
    cout << "answer:" << count << endl;
    

    return 0;
}
