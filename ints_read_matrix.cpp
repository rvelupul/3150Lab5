#include <istream>
#include <sstream>
#include <vector>

#include "ints_read_vector.h"
#include "ints_read_matrix.h"

using namespace std;


vector<vector<int>> ints_read_matrix(istream & in_stream) {
    vector<vector<int>> matrix;
    string line;
    
    while (getline(in_stream, line)) { // Use getline directly in the loop condition
        istringstream is_line(line);
        matrix.push_back(ints_read_vector(is_line)); // Make sure to use the correct function to read a vector from the stream
    }

    return matrix;
}
