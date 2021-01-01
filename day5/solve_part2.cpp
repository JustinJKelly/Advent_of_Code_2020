#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int main(int argc, char** argv) {

    if (argc < 2) {
        cout << "no argument" << endl;
        return 0;
    }
    
    string filename = argv[1];
    ifstream file (filename);
    string line;
    int rows = 127;
    int columns = 8;
    vector<int> seats; 
    
    if (file.is_open()) {
        while (getline(file, line)) {
            replace( line.begin(), line.end(), 'F', '0');
            replace( line.begin(), line.end(), 'B', '1');
            replace( line.begin(), line.end(), 'R', '1');
            replace( line.begin(), line.end(), 'L', '0');

            int row = 0;
            int v = 6;
            for (int i = 0; i < line.size()-3; ++i) {
                if (line[i] == '1') row += (pow(2.0, v));
                --v;
            }
            
            int seat = 0;
            v = 2;
            for (int i = line.size()-3; i < line.size(); ++i) {
                if (line[i] == '1') seat += (pow(2.0, v));
                --v;
            }

            seats.push_back( (row * 8) + seat );
        }
        file.close();
    } else {
        cout << "unable to open file" << endl;
    }
            
    int row = 0;
    sort (seats.begin(), seats.end());
    
    vector<int> answer;
    for (int j = 1; j < seats.size()-1; ++j) {
        if ( (seats[j-1] != (seats[j] - 1)) || (seats[j+1] != seats[j] + 1) ) {
            //cout << seats[j] << endl;
            answer.push_back(seats[j]);
        }
    }    

    cout << "answer:" << (answer[1] + answer[0]) / 2 << endl;

    return 0;
}
