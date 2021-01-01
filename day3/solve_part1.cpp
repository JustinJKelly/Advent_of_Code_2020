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
    
    //1 = tree, 0 = open
    vector<vector<int>> input;
    
    if (file.is_open()) {
        while (getline(file, line)) {
            vector<int> v;
            for (size_t j = 0; j < line.size(); ++j) {
                v.push_back( (line[j] == '.') ? 0 : 1);
            }
            input.push_back(v);
        }
        file.close();
    } else {
        cout << "unable to open file" << endl;
    }
    int lines = input.size();
    int width = input[0].size();
    int amount = (lines*3);

    for (int i = 0; i < lines; ++i) {
        vector<int> updated;
        for (int j = 0; j < amount; j+=width) {
            if (amount > (j + width)) {
                updated.insert(updated.end(), input[i].begin(), input[i].end());            
            } else {
                int k = amount - j;
                updated.insert(updated.end(), input[i].begin(), input[i].begin() + k);
            }
        }
        input[i] = updated;
    }
    
    int count_trees = 0;
    for (int i = 1, j = 3; i < input.size() && j < input[i].size(); ++i, j+=3) {
        if (input[i][j] == 1) {
            count_trees += 1;
        }
    }

    cout << "answer:" << count_trees << endl;
    return 0;
}
