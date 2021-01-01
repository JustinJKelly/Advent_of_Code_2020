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
    int max_seat = 0; 
     
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
            //cout << "row:" << row << endl;

            int seat = 0;
            v = 2;
            for (int i = line.size()-3; i < line.size(); ++i) {
                if (line[i] == '1') seat += (pow(2.0, v));
                --v;
            }
            //cout << "seat:" << seat << endl;
            //cout << "seat id:" << (row*8) + seat << endl << endl;
            
            if (max_seat < ((row*8) + seat)) {
                max_seat = ((row*8) + seat);
            }
        }
        file.close();
    } else {
        cout << "unable to open file" << endl;
    }
    
    cout << "answer:" << max_seat << endl;

    return 0;
}
