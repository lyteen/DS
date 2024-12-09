#include <iostream>
#include "graph.hpp"
using namespace std;

int main() {
    // Create a graph with 4 vertices
    Graph g(4);

    // Add some edges
    g.add_edge(0, 1, 10);  // Edge 0 -> 1 with weight 10
    g.add_edge(0, 2, 5);   // Edge 0 -> 2 with weight 5
    g.add_edge(1, 2, 2);   // Edge 1 -> 2 with weight 2
    g.add_edge(2, 3, 7);
    g.add_edge(0, 3, 4);
    g.add_edge(3, 1, 5);


    g.print_graph();
    cout << "graph number of edges:" << g.get_edge_count() << endl;

    g.del_edge(0, 1);

    g.print_graph();
    cout << "graph number of edges:" << g.get_edge_count() << endl;

    g.dfs(3);
    g.bfs(3);
    g.prim_algo(1);
} 