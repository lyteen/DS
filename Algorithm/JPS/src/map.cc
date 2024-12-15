#include <vector>
#include <set>

#include "map.hpp"

using namespace std;

vector<vector<int>> Map::grid_map_user_defined(int width, int height, int board_size, const vector<pair<int, int>> &obstacles)
{
    grid = vector<vector<int>>(height, vector<int>(width, 0));
    /*
    TODO:   How "this" work?
    */
   // Add the obstacles
    this->obstacles = set<pair<int, int>>(obstacles.begin(), obstacles.end());
    
    for (int i = board_size; i < width - board_size; ++i)
    {
        this -> obstacles.insert({board_size, i});
        this -> obstacles.insert({height - board_size, i});
    }
    for (int j = board_size; j < height - board_size; ++j)
    {
        this -> obstacles.insert({j, board_size});
        this -> obstacles.insert({j, width - board_size});
    }
    for (const auto& obstacle : this -> obstacles)
    {
        grid[obstacle.first][obstacle.second] = 1;
    }

    return grid;
}