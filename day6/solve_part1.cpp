#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <unordered_set>
using namespace std;

int main(int argc, char** argv) {

    if (argc < 2) {
        cout << "no argument" << endl;
        return 0;
    }
    
    string filename = argv[1];
    ifstream file (filename);
    string line;
    int count = 0;
    unordered_set<char> set;    
 
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line != "") {
                for (char ch: line) set.insert(ch);
            } else {
                count += set.size();
                set.clear();
            }   
        }
        file.close();
    } else {
        cout << "unable to open file" << endl;
    }
    count += set.size();
    
    cout << "answer:" << count << endl;
    

    return 0;
}
