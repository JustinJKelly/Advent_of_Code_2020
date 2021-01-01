#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <unordered_set>
using namespace std;

int main() {
    ifstream file ("input.txt");
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
    
    cout << count << endl;
    

    return 0;
}
