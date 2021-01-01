#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
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
    vector<int> integers (201,0);
    vector<pair<pair<int,int>, int>> adds; 

    if (file.is_open()) {
        int j = 1;
        while (getline(file, line)) {
            int i = stoi(line);
            integers[j++] = i;
        }
        file.close();
    } else {
        cout << "unable to open file" << endl;
    }

    int j = 1;
    for (int i = 1; i < integers.size(); ++i) {
        for (int k = 1; k < integers.size(); ++k) {
            if (i != k) {
                if ((integers[i] + integers[k]) < 2020) { 
                    adds.push_back(make_pair( make_pair(integers[k], integers[i]), 2020 - (integers[i] + integers[k])));
                }
            }   
        }
    }
    
    /*for (int i = 0; i < adds.size(); ++i) {
        cout << adds[i].first.first << " " << adds[i].first.second << " " << adds[i].second << endl;
    }*/

    for (int i = 0; i < adds.size(); ++i) {
        for (int k = 1; k < integers.size(); ++k) {
            if (integers[k] == adds[i].second) {
                cout << "i:" << integers[k] << "  j:" << adds[i].first.first << "  k:" << adds[i].first.second << " ";
                //cout << integers[k] + adds[i].first.first + adds[i].first.second << endl;
                cout << "(i*j*k):" << integers[k] * adds[i].first.first * adds[i].first.second << endl;
            }
        }
    }
    
    return 0;
}
