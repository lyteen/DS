#include "G_ad_matrix.hpp"

Graph::Graph(int numbers_v){
    this->n_vertexs = numbers_v;
    this->n_edges = 0;
    adjacency_matrix = new int* [n_vertexs]; // init the rows of adjecency matrix
    for(int i = 0; i < n_vertexs; i++){
        adjacency_matrix[i] = new int[n_vertexs]; // init the cols of adjecency matrix
        for(int j = 0; j < n_vertexs; j++){
            adjacency_matrix[i][j] = Status::NoEdge; // Status::NoEdge init "-1"
        }
        adjacency_matrix[i][i] = Status::Diagonal;
    }
}

Graph::~Graph(){
    for(int i = 0; i < n_vertexs; i++){
        delete[] adjacency_matrix[i]; // release the each rows of matrix
    }
    delete[] adjacency_matrix; // release the matrix of save the int type pointer
}

void Graph::print_graph() const{
    cout << "adjacency matrix graph: " << endl;
    for(int i = 0; i < n_vertexs; i++){
        for(int j = 0; j < n_vertexs; j++){
            cout << adjacency_matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Graph::add_edge(int vertex1, int vertex2, int weight){
    // check the isnt error
    if(vertex1 < 0 || vertex2 < 0 || vertex1 > n_vertexs - 1 || vertex2 > n_vertexs - 1 || vertex1 == vertex2){
        cout << "Error vertex: " << vertex1 << " or " << vertex2 << " the n_vertexs is: " << n_vertexs << endl;
        return;
    }
    if(adjacency_matrix[vertex1][vertex2] != Status::NoEdge || adjacency_matrix[vertex2][vertex1] != Status::NoEdge){
        cout << "[" << vertex1 << "]" << "[" << vertex2 << "]" << " already have edge, weight is: " << adjacency_matrix[vertex1][vertex2] << endl;
        return;
    }
    adjacency_matrix[vertex1][vertex2] = weight;
    adjacency_matrix[vertex2][vertex1] = weight;
    n_edges += 1;
}

void Graph::del_edge(int vertex1, int vertex2){
    if(vertex1 < 0 || vertex2 < 0 || vertex1 > n_vertexs - 1 || vertex2 > n_vertexs - 1 || vertex1 == vertex2){
        cout << "Error vertex: " << vertex1 << " or " << vertex2 << " the n_vertexs is: " << n_vertexs << endl;
        return;
    }
    if(adjacency_matrix[vertex1][vertex2] == Status::NoEdge || adjacency_matrix[vertex2][vertex1] == Status::NoEdge){
        cout << "[" << vertex1 << "]" << "[" << vertex2 << "]" << " not have edge " << endl;
        return;
    }
    adjacency_matrix[vertex1][vertex2] = Status::NoEdge;
    adjacency_matrix[vertex2][vertex1] = Status::NoEdge;
    n_edges -= 1;
}

void Graph::dfs_utils(int start_vertex, vector<bool>& visited){
    cout << "->" << start_vertex;
    for(int adj_vertex = 0; adj_vertex < n_vertexs; adj_vertex++){
        if(!visited[adj_vertex] && adjacency_matrix[start_vertex][adj_vertex] != -1 && start_vertex != adj_vertex){
            visited[adj_vertex] = true;
            dfs_utils(adj_vertex, visited); // from the adjacency vertex traverse
        }
    }
    return;
}

void Graph::dfs(int start_vertex){
    vector<bool> visited(n_vertexs, false);
    cout << "dfs: from vertex <" << start_vertex << ">: ";
    visited[start_vertex] = true;
    dfs_utils(start_vertex, visited);
    cout << endl;
    return;
}

void Graph::bfs(int start_vertex){
    vector<bool> visited(n_vertexs, false);
    cout << "bfs: from vertex <" << start_vertex << ">: ";
    queue<int> queue; // queue save the next to visit vertex
    queue.push(start_vertex);
    visited[start_vertex] = true;

    while(!queue.empty()){
        int vertex = queue.front();
        queue.pop();
        cout << "->" << vertex;

        for(int adj_vertex = 0; adj_vertex < n_vertexs; adj_vertex++){
            if(adjacency_matrix[adj_vertex][vertex] != -1 && !visited[adj_vertex] && start_vertex != adj_vertex){
                visited[adj_vertex] = true;
                queue.push(adj_vertex);
            }
        }
    }
}