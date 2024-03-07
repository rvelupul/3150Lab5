# 3150Lab5

1). To compile code, type g++ main_graph_read_all_three.cpp ints_read_matrix.cpp ints_read_vector.cpp ints_write.cpp

Then type ./a.out

2). To compile code, type g++ unit_tests.cpp ints_read_matrix.cpp ints_read_vector.cpp ints_write.cpp

Then type ./a.out


How the algorithm works with the barbell graph:

The algorithm provided, Expensive-Digraph-exact-paths, can be applied to any directed graph, including barbell graphs. A barbell graph consists of two complete graphs (cliques) connected by a path. Let's consider how the algorithm works with a barbell graph:

Initialization: The algorithm starts by initializing adjacency matrices representing the directed graph. For a barbell graph, this involves setting up matrices for D(-1), D(0), and D(+1) based on the connectivity and costs between nodes.

Computing exact paths: The algorithm iterates over the matrices and computes exact paths in the graph. It evaluates the conditions based on the costs between nodes to determine the reachability and path lengths. For a barbell graph, this involves considering the connections between nodes in each clique as well as the path connecting the cliques.

Result: After applying the algorithm, the resulting matrices represent the reachability and exact paths in the barbell graph. Each entry in the matrices indicates whether there exists a path between two nodes and the cost of reaching one node from another.

However, the Expensive-Digraph-exact-paths algorithm analyzes the directed graph structure and costs between nodes to determine reachability and exact paths. When applied to a barbell graph, it considers the connections within each clique and the connecting path between the cliques to compute the paths accurately.
