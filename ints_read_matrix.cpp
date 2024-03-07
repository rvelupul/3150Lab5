#include <istream>
#include <sstream>
#include <vector>

#include "ints_read_vector.h"
#include "ints_read_matrix.h"

using namespace std;


vector<vector<int>> ints_read_matrix(istream & in_stream) {
    vector<vector<int>> matrix;
    string line;
    
    while (getline(in_stream, line)) { 
        istringstream is_line(line);
        matrix.push_back(ints_read_vector(is_line)); 
    }

    return matrix;
}