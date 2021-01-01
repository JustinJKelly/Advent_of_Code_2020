#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <regex>
using namespace std;

bool checkValid(string passport, vector<string> fields) {
    
    for (int i = 0; i < fields.size(); ++i) {
        if (passport.find(fields[i]) == string::npos) {
            //cout << passport << endl;
            if (fields[i] == "cid") continue;
            //cout << passport << endl << endl; 
            return false;
        } else {
            string sub = passport.substr(passport.find(fields[i]));
            //cout << sub << endl<< endl;
            string sub2 = sub.substr(sub.find(":")+1);
            //cout << sub2 << endl << endl;
            size_t found = sub2.find(" ");
            string res; 

            if ( (found != string::npos) || (found > sub2.find(':')) ) {
                res = sub2.substr(0, sub2.find(':')-3);
            } else if ( (found != string::npos) || (found > sub2.find('\r')) ) {
                res = sub2.substr(0, sub2.find('\r'));
            } else {
                res = sub2.substr(0, found);
            }   

            if (res[res.size()-1] == ' ') res = res.substr(0, res.size()-1);
            //cout << fields[i] << ":" << res << endl; 
            
            if (fields[i] == "byr") {
                if ( (stoi(res) < 1920) || (stoi(res) > 2002)) {
                    //cout <<  fields[i] << ":" << res << " "  << passport << endl << endl;
                    return false;
                }
            } else if (fields[i] == "iyr") {
                if ( (stoi(res) < 2010) || (stoi(res) > 2020)) {
                    //cout <<  fields[i] << ":" << res << " "  << passport << endl << endl;
                    return false;
                }
            } else if (fields[i] == "eyr") {
                if ( (stoi(res) < 2020) || (stoi(res) > 2030)) {
                    //cout <<  fields[i] << ":" << res << " "  << passport << endl << endl;
                    return false;
                }
            } else if (fields[i] == "hgt") {
                if ( res.find("in") != string::npos) {
                    string height = res.substr(0, res.find("in"));
                    if ( (stoi(height) < 59) || (stoi(height) > 76) ) {
                        //cout <<  fields[i] << ":" << res << " "  << passport << endl << endl;
                        return false;
                    }
                } else {
                    string height = res.substr(0, res.find("cm"));            
                    if ( (stoi(height) < 150) || (stoi(height) > 193) ) {
                        //cout <<  fields[i] << ":" << res << " "  << passport << endl << endl;
                        return false;
                    }
                }
            } else if (fields[i] == "ecl") {
                unordered_set<string> set = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
                if (set.find(res) == set.end()) {
                    //cout << fields[i] << ":" << res << " "  << passport << endl << endl;
                    return false;
                }
            } else if (fields[i] == "hcl") {
                unordered_set<char> chars = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
                if ( (res[0] != '#') || res.size() != 7)  {
                    //cout <<  fields[i] << ":" << res << " "  << passport << endl << endl;
                    return false;
                } 
                for (int i = 1; i < res.size(); ++i) {
                    if (chars.find(res[i]) == chars.end()) {
                        //cout << fields[i] << ":" << res << " " << passport << endl << endl;
                        return false;
                    }
                }
            } else if (fields[i] == "pid") {
                unordered_set<char> chars = {'0','1','2','3','4','5','6','7','8','9'};
                if (res.size() != 9) {
                    //cout <<  res.size() << fields[i] << ":" << res << " "  << passport << endl << endl;
                    return false;
                }
                for (int i = 0; i < res.size(); ++i) {
                    if (chars.find(res[i]) == chars.end()) { 
                        //cout << fields[i] << ":" << res << " " << passport << endl << endl;
                        return false;
                    }
                }
            }
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
                //return 0;
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
