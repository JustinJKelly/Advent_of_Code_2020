#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_set>
#include <cmath>
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
    vector<long double> array;
    

    if (file.is_open()) {
        while (getline(file, line)) {
            array.push_back(stold(line));
        }
        file.close();
    } else {
        cout << "unable to open file" << endl;
    }

    vector<vector<long double>> dp (array.size(), vector<long double>(array.size(), 0));
    for (size_t i = 0; i < array.size(); ++i) {
        dp[0][i] =  array[i];
    }

    for (int i = 1; i < array.size(); ++i) {
        for (int j = i; j < array.size(); ++j) {
            dp[i][j] = dp[i-1][j-1] + dp[0][j];
            
            if ((dp[i][j]) == 85848519) {
                int l = 0;
                vector<int> a;
                
                while (l != 85848519) {
                    l += int(dp[0][j]);
                    a.push_back(dp[0][j]);
                    --j;
                }

                sort(a.begin(), a.end());
                /*for (size_t i = 0; i < a.size(); ++i) {
                    cout << a[i] << " ";
                }
                cout << endl;*/

                cout << "answer:" << to_string(a[0] + a[a.size()-1]) << endl;
                return 0;
            } 
        }
    }

    return 0;
}
