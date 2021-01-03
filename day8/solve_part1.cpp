#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <unordered_set>
#include <utility>
using namespace std;

int acc(vector< pair<int,string> > &lines, int n) {

    //cout << "n:" << n << "   bit:" << lines[n].first << "   line:" << lines[n].second << endl; 
    if (lines[n].first == 1) {
        return 0;
    }

    string line = lines[n].second;
    lines[n].first = 1;

    if (line.substr(0,3) == "nop") {
        return acc(lines, n+1);
    } else if (line.substr(0,3) == "acc") {
        string sub = line.substr(line.find(' ')+1);
        if (sub[0] == '-') {
            //cout << "-" << stoi(sub.substr(1)) << endl;
            return acc(lines, n + 1) - stoi(sub.substr(1));
        } else {
            //cout << "+" << stoi(sub.substr(1)) << endl;
            return acc(lines, n + 1) + stoi(sub.substr(1));
        }
    } else {
        string sub = line.substr(line.find(' ')+1);
        if (sub[0] == '-') 
            return acc(lines, n - stoi(sub.substr(1)));
        else 
            return acc(lines, n + stoi(sub.substr(1)));
    }
}

int main(int argc, char** argv) {

    if (argc < 2) {
        cout << "no argument" << endl;
        return 0;
    }
    
    string filename = argv[1];
    ifstream file (filename);
    string line;
    vector<pair<int,string>> lines;   
 
    if (file.is_open()) {
        while (getline(file, line)) {
            lines.push_back(make_pair(0,line));

        }
        file.close();
    } else {
        cout << "unable to open file" << endl;
    }

    int n = acc(lines, 0);
    cout << "answer:" << n << endl;
    
    /*for (size_t i = 0; i < lines.size(); ++i) {
        cout << lines[i].first << " " << lines[i].second << endl;
    }*/

    return 0;
}
