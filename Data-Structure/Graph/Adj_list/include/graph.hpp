#ifndef GRAPH
#define GRAPH
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct  Node{
    int adjVex;
    int w;
    Node* nextArc; // point the next vertex.
};

struct Compare {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first >= b.first;
    }
};
// define the Graph class
class Graph{
private:
    int n; // number of vertexs
    int n_edges; // number of edges
    Node** adjacency; // Array of pointers to the adjacency list

public:
    Graph(int number_v);
    ~Graph(); // destructor to free dynamically allocated memory
    inline int get_edge_count() const;
    inline int get_vertex_count() const;
    void add_edge(int vertex1, int vertex2, int weight);
    void print_graph() const;
    void del_edge(int vertex1, int vertex2);
    void dfs_utils(int vertex, vector<bool>& visited) const;
    void dfs(int vertex) const;
    void bfs_utils(int vertex, vector<bool>& visited) const;
    void bfs(int vertex) const;
    void prim_algo(int start_vertex) const;
};
#endif