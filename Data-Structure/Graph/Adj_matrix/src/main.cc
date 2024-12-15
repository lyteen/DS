#include <iostream>
#include "G_ad_matrix.hpp"
int main(){
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

    int vertex1 = 0;
    int vertex2 = 1;
    g.del_edge(vertex1, vertex2);
    cout << "delect edge: " << "("  << vertex1 << "," << vertex2 << ")" << endl;
    g.print_graph();
    cout << "graph number of edges:" << g.get_edge_count() << endl;

    g.dfs(3);
    g.bfs(3);
}