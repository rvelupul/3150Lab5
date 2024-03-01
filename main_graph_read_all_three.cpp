#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include "ints_read_matrix.h"
#include "ints_write.h"

const int INF = INT_MAX / 2;


int main() {
    using namespace std;


    string files[] = { "graph_0.txt", "graph_1.txt", "graph_m1.txt" };
    ifstream in_file_0(files[0]), in_file_1(files[1]), in_file_m1(files[2]);


    if (!in_file_0 || !in_file_1 || !in_file_m1) {
        cerr << "Error opening input files." << endl;
        return 1;
    }


    vector<vector<int>> D[3] = {
        ints_read_matrix(in_file_0),
        ints_read_matrix(in_file_1),
        ints_read_matrix(in_file_m1)
    };


    in_file_0.close();
    in_file_1.close();
    in_file_m1.close();


    int n = D[0].size(); 

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int g = -1; g <= 1; ++g) {
                if (D[g + 1][i][j] != 2) { 
                    D[g + 1][i][j] = g; 
                } else {
                    D[g + 1][i][j] = INF; 
                }
            }
        }
    }

    for (int l = 0; l < 3 * n * n + 1; ++l) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                  
                    if (D[0][i][k] + D[0][k][j] == 0) {
                        D[0][i][j] = 0;
                    }
                
                    if (D[2][i][k] + D[0][k][j] == 1 || D[0][i][k] + D[2][k][j] == 1) {
                        D[2][i][j] = 1;
                    }
                   
                    if (D[0][i][k] + D[1][k][j] == -1 || D[1][i][k] + D[0][k][j] == -1) {
                        D[1][i][j] = -1;
                    }
                }
            }
        }
    }

    cout << "D(-1) Matrix:" << endl << D[1];
    cout << "D(0) Matrix:" << endl << D[0];
    cout << "D(1) Matrix:" << endl << D[2];


    return 0;
}




