#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <sstream>
#include <iterator>
#include <algorithm>
#include "ints_write.h"

using namespace std;

const int INF = numeric_limits<int>::max();

vector<vector<int>> readMatrixFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    vector<vector<int>> matrix;
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        vector<int> row((istream_iterator<int>(iss)),
                        istream_iterator<int>());
        matrix.push_back(row);
    }
    file.close();
    return matrix;
}

vector<vector<vector<int>>> initAdjacencyMatrices(const vector<vector<int>>& G_minus_one,
                                                  const vector<vector<int>>& G_zero,
                                                  const vector<vector<int>>& G_plus_one) {
    return {G_minus_one, G_zero, G_plus_one};
}


void expensiveDigraphExactPaths(vector<vector<vector<int>>>& G) {
    int n = G[0].size(); 
    for (int l = 2; l <= 3 * n * n + 1; ++l) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    
                    if (G[0][i][k] != INF && G[2][k][j] != INF && (G[0][i][k] + G[2][k][j]) == 0) G[1][i][j] = 0;
                    if (G[2][i][k] != INF && G[1][k][j] != INF && (G[2][i][k] + G[1][k][j]) == 1 && G[1][i][j] < INF) G[1][i][j]++;
                    if (G[0][i][k] != INF && G[1][k][j] != INF && (G[0][i][k] + G[1][k][j]) == -1 && G[0][i][j] > -INF) G[0][i][j]--;
                }
            }
        }
    }
}

int main() {
    vector<vector<int>> D_minus_one = readMatrixFromFile("graph_m1.txt");
    vector<vector<int>> D_zero = readMatrixFromFile("graph_0.txt");
    vector<vector<int>> D_plus_one = readMatrixFromFile("graph_1.txt");

    for (auto& row : D_zero) {
        replace(row.begin(), row.end(), 2, INF);
    }

    vector<vector<vector<int>>> adjacency_matrices = initAdjacencyMatrices(D_minus_one, D_zero, D_plus_one);

    expensiveDigraphExactPaths(adjacency_matrices);

    for (auto& row : adjacency_matrices[1]) {
        replace(row.begin(), row.end(), INF, 2);
    }

    cout << "D(-1) Matrix:" << endl;
    cout << adjacency_matrices[0] << endl;
    cout << "D(0) Matrix:" << endl;
    cout << adjacency_matrices[1] << endl;
    cout << "D(+1) Matrix:" << endl;
    cout << adjacency_matrices[2] << endl;

    return 0;
}
