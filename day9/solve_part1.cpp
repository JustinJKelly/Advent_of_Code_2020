#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

bool checkValid(vector<double> array, int start, int end) {
    unordered_set<int> set;
    int target = array[end];
    //cout << "target:" << target << endl;
    for (size_t i = start; i < end; ++i) {
        //cout << (target-array[i]) << "   " << array[i] << endl;
        if (set.find(target-array[i]) != set.end()) {
            return true;
        } else {
            set.insert(array[i]);
        }
    }

    return false;
}

int main(int argc, char** argv) {

    if (argc < 2) {
        cout << "no argument" << endl;
        return 0;
    }
    
    string filename = argv[1];
    ifstream file (filename);
    string line;
    vector<double> array;
    

    if (file.is_open()) {
        while (getline(file, line)) {
            //cout << line << endl;
            array.push_back(stod(line));
        }
        file.close();
    } else {
        cout << "unable to open file" << endl;
    }

    for (size_t i = 25; i < array.size(); ++i) {
        if (!checkValid(array, i-25, i)) {
            cout << "answer:" << (int) array[i] << "   i:" << i << endl; 
            return 0;
        }
    }

    return 0;
}
