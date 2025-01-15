# **README**

structure in `include\.hpp`

## **adj_list**

reference:
![](Adj_list/refers/adjecency_list.png)

1. **Graph**

    init the adjacency list. `adjacency = new Node* [n]` adjacency store n Node* pointer.
    return void

2. **dfs and dfs_utils**

    from start_vertex, recursive the relaitive adjacent vertex.;like:
    vectex1->1vectex2->2vectex3

    `while(vextex=vextex->adjacency)...if(!visited[vectex]), then dfs_utils(vectex, visited)`
    return void

3. **bfs and bfs_utils**

    from start_vertex get the all relative adjacent vertex.like:
    vertex1->1vertex2, 1vertex3, 1vertex4

    `while(vextex=vextex->adjacency)...if(!visited[vectex]), then queue.push(vectex)`
    return void
4. **prim_algo**

    through `priority_queue` get the adjacency vertex smallest cost 
    return void