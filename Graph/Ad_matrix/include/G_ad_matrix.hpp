#ifndef G_AD_MATRIX
#define G_AD_MATRIX
#define ElemType int
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// define the adjacency matrix graph
class Graph{
private:
    ElemType** adjacency_matrix;
    int n_vertexs;
    int n_edges;
    ElemType noEdge;
public:
    Graph(int numbers_v);
    ~Graph();
    int get_edge_count() const;
    int get_vertex_count() const;
    void print_graph() const;
    void add_edge(int vertex1, int vertex2, int weight);
    void del_edge(int vertex1, int vertex2);
    void dfs_utils(int start_vertex, vector<bool>& visited);
    void dfs(int start_vertex);
    void bfs(int start_vertex);
};
#endif