#ifndef JPS_HPP
#define JPS_HPP

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;
/*
    -Parameter:
        grid: save map if 1 show is the obstable
        start: start node
        goal: target node
        radius: ? No Use, may can use show can seen map
        board_size: map board begin, generally 0
        closed: save jumppoint
        path: save move path
        visited: save visited node to show fig
    -Method:
        plan: path planning total method
        heuristic: compute cost
        visulize_grid: by visited show fig
        Jump: recursion generally situation and move to jumppoint
        findForcedNeighbor: sore algorithm find jumppoint
*/
class JPS
{
public:
    JPS(vector<vector<int>> grid, pair<int, int> start, pair<int, int> goal, int radius, int board_size);
    double plan();
    double heuristic(pair<int,int> node, pair<int, int> target);
    void visualize_grid(double cost);
    pair<int,int> Jump(pair<int,int> node, pair<int,int> direction);
    bool findForcedNeighbor(const pair<int,int> &node,const pair<int,int> &direction);

private:
    vector<vector<int>> grid; 
    pair<int,int> start;
    pair<int,int> goal;
    int radius;
    int board_size;
    set<pair<int,int>> closed;
    vector<pair<int,int>> path;
    vector<pair<int,int>> visited;
};
#endif // JPS_HPP