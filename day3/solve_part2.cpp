#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int get_num_trees(int move_down, int move_right, vector< vector<int> > input) {
    int count_trees = 0;
    for (int i = move_down, j = move_right; i < input.size() && j < input[i].size(); i+=move_down, j+=move_right) {
        if (input[i][j] == 1) {
            count_trees += 1;
        }
    }
    return count_trees;
}

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
    int amount = (lines*7);

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
    /*cout << lines << " " << width << " " << amount << endl;
    for (int i = 0; i < input.size(); ++i) {
        for (int j = 0; j < input[i].size(); ++j) {
            cout << input[i][j];
        }
        cout << endl;
    }*/

    int r1d1 = get_num_trees(1, 1, input);
    int r3d1 = get_num_trees(1, 3, input);
    int r5d1 = get_num_trees(1, 5, input);
    int r7d1 = get_num_trees(1, 7, input);
    int r1d2 = get_num_trees(2, 1, input);

    long long l = (long long) (r1d1);
    l *= (long long) r3d1;
    l *= (long long) r5d1;
    l *= (long long) r7d1;
    l *= (long long) r1d2; 
    cout << r1d1 << " " << r3d1 << " " << r5d1 << " " << r7d1 << " " << r1d2 << "  answer(mult all numbers):" << l << endl;
    

    
    return 0;
}    
