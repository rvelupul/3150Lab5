#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "ints_read_matrix.h"
#include <sstream>
#include <vector>
#include <climits>

const int INF = INT_MAX / 2;

TEST_CASE("Testing ints_read_matrix with istringstream") {
    std::string input_matrix = "0 2\n2 0\n";
    std::istringstream iss(input_matrix);
    auto matrix = ints_read_matrix(iss);

    CHECK_EQ(matrix.size(), 2);
    CHECK_EQ(matrix[0][0], 0);
    CHECK_EQ(matrix[1][1], 0);
}

TEST_CASE("Verify matrix initialization and updates") {
    std::vector<std::vector<int>> D0 = {{0, 2}, {2, 0}};
    std::vector<std::vector<int>> D1 = {{2, 1}, {1, 2}};
    std::vector<std::vector<int>> Dm1 = {{-1, 2}, {2, -1}};
    
    for (auto& row : D0) {
        for (auto& val : row) {
            if (val == 2) val = INF;
        }
    }

    REQUIRE_EQ(D0[0][1], INF); 
    CHECK_EQ(Dm1[0][0], -1);
}

TEST_CASE("Check for non-existent paths") {
    std::vector<int> row = {INF, INF};
    CHECK_FALSE(row[0] == 0);
    CHECK_FALSE(row[1] == -1);
}

TEST_CASE("Warning for potential issues") {
    WARN("Ensure matrix updates do not introduce incorrect path costs.");
}

TEST_CASE("Testing ints_read_matrix with empty input") {
    std::string input_matrix = "";
    std::istringstream iss(input_matrix);
    auto matrix = ints_read_matrix(iss);

    CHECK(matrix.empty()); 
}