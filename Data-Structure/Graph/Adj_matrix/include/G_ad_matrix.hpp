#ifndef G_AD_MATRIX
#define G_AD_MATRIX
#define ElemType int
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// defind the adjacency matrix status
enum Status{
    Diagonal,
    NoEdge = -1
};

// define the adjacency matrix graph
class Graph{
private:
    ElemType** adjacency_matrix;
    int n_vertexs;
    int n_edges;
public:
    Graph(int numbers_v);
    ~Graph();

    inline constexpr int get_edge_count() const {
        return n_edges;
    }

    inline constexpr int get_vertex_count() const {
        return n_vertexs;
    }
    void print_graph() const;
    void add_edge(int vertex1, int vertex2, int weight);
    void del_edge(int vertex1, int vertex2);
    void dfs_utils(int start_vertex, vector<bool>& visited);
    void dfs(int start_vertex);
    void bfs(int start_vertex);
};
#endif