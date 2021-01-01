#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool checkValid(string passport, vector<string> fields) {
    for (int i = 0; i < fields.size(); ++i) {
        if (passport.find(fields[i]) == string::npos) {
            //cout << passport << endl;
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {

    if (argc < 2) {
        cout << "no argument" << endl;
        return 0;
    }
    
    string filename = argv[1];
    ifstream file (filename);
    string line;
    string passport;
    int count_valid = 0;
    vector<string> fields = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
    
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line == "") {
                if (checkValid(passport, fields)) {
                    count_valid++;
                }   
                passport = "";
            } else {
                passport += line;
            }
        }
        file.close();
    } else {
        cout << "unable to open file" << endl;
    }

    if (passport != "") { 
        if (checkValid(passport, fields)) ++count_valid;
    }
    
    cout << "answer:" << count_valid << endl;

    return 0;
}
