#include <iostream>
#include <vector>
#include <utility> // Use pair
#include <cmath>

#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include "jps.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;

/*
TODO:   thinking the radius work
*/
JPS::JPS(vector<vector<int>> grid, pair<int, int> start, pair<int, int> goal, int radius, int board_size) 
        :grid(grid), start(start), goal(goal), radius(radius), board_size(board_size) {}


double JPS::heuristic(pair<int, int> node, pair<int, int> target) {
    /*
    compute the cost from current node to target node
    */
   double dx = abs(node.first - target.first);
   double dy = abs(node.second - target.second);

   // Use Euclidean Distance compute cost
   return sqrt(dx * dx + dy * dy);
}

bool JPS::findForcedNeighbor(const pair<int, int> &current_node, const pair<int, int> &direction) {
    /*
        - Rule:
            Not obstacle:
                1.Straight find: if dont pass current node from parent node to target node cost smaller or equit
                  the cost that from parent node pass current node to target node then is Inferior Neighbors
                2.Diagonal find: rule is same, search type is diagonal 
            Obstacle:
                1.Since obstacle make from parent node to target must pass the current node, so call the target node is Forced Neighbors 
        - Parameters:
            current_node: First dimention is x-axis, Second dimention is y-axis
            direction: Use for determining whether is a forced neighbor
        - Return:
            bool: True if a forced neighbor exists otherwise False
    */
   // Vertical Move
   /*

            ?    ?    0         0    ?    ?
            ? <- X -> 1    or   1 <- x -> ?
            ?    ?    0         0    ?    ?

   */
   if (direction.first != 0 && direction.second == 0) { // Vertical move
        if ((grid[current_node.first][current_node.second + 1] != 0 && grid[current_node.first + direction.first][current_node.second + 1] == 0) ||
            (grid[current_node.first][current_node.second - 1] != 0 && grid[current_node.first + direction.first][current_node.second - 1] == 0)){
                return true;
            }
   }
   //horizontal Move
   /*

            0    1    0         ?    ?    ?
            ? <- X -> ?    or   ? <- x -> ?
            ?    ?    ?         0    1    0


   */
    if (direction.first == 0 && direction.second != 0) {
        if ((grid[current_node.first + 1][current_node.second] != 0 && grid[current_node.first + 1][current_node.second + direction.second] == 0) ||
            (grid[current_node.first - 1][current_node.second] != 0 && grid[current_node.first - 1][current_node.second + direction.second] == 0)){
                return true;
            }
    }
    // diagonal Move
    /*

             0    ?    0         0    1    0
             1 <- X -> 1    or   ? <- x -> ?
             0    ?    0         0    1    0

    */
    if (direction.first != 0 && direction.second != 0) {
        if ((grid[current_node.first][current_node.second + direction.second] != 0 && grid[current_node.first + direction.first][current_node.first + direction.second] == 0) ||
        (grid[current_node.first + direction.first][current_node.second] != 0 && grid[current_node.first + direction.first][current_node.first + direction.second] == 0)){
            return true;
        }
    }

    return false;
}
/*
    Thinking:   If meet the board how do?
    -Return Situation:
        1.return obstable node {-1, -1}
        2.return goal node
        3.
*/
pair<int, int> JPS::Jump(pair<int, int> node, pair<int, int> direction) {
    /*
        -Parameter:
        -Direction:
    */
   pair<int, int> next_node = {node.first + direction.first, node.second + direction.second};
   if (grid[next_node.first][next_node.second] == 1) {
    // Met the obstacle
        return {-1, -1};
   }
   if (next_node == goal) {
        return next_node;
   }
   if (findForcedNeighbor(next_node, direction)) {
        // If is True return ForcedNeighbor
        return next_node;
   }

   if (direction.first != 0 && direction.second != 0) {
        pair<int, int> dy = {direction.first, 0};
        pair<int, int> dx = {0, direction.second};
        if (Jump(next_node, dy).first != -1 || Jump(next_node, dx).first != -1) {
            return next_node;
        }
   }
   // If can pass,then recursion the generally nodes
   return Jump(next_node, direction);
}

double JPS::plan() {
    /*
    TODO: instead of queue to your prior_queue
    */
    priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> open;
    map<pair<int, int>, double> path_cost;

    path_cost[start] = 0;
    // open is the private variety
    
    open.push({heuristic(start, goal), start});
    map<pair<int, int>, pair<int, int>> parents;

    vector<pair<int, int>> nexts = {{-1, 0},{0, 1},{0, -1},{1, 0},{-1, 1},{1, -1},{1, 1},{-1, -1}};

    while (!open.empty()) {
        /*
        TODO: what is current_f and current_node, and how work?
        */
        auto [current_f, current_node] = open.top();
        open.pop();

        if (closed.find(current_node) != closed.end()) continue; // Skip it if current node has been in closed
        closed.insert(current_node);

        if (current_node == goal) {
            // Path is private variety save path
            path.clear(); // Release stored
            while (current_node != start) {
                path.push_back(current_node);
                current_node = parents[current_node];
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            return path_cost[goal];
        }

        for (auto& next:nexts) {
            pair<int, int> jumppoint = Jump(current_node, next);
            if (jumppoint.first > 0) {
                if (closed.find(jumppoint) == closed.end()) {
                    double h = heuristic(jumppoint, goal);
                    double g = path_cost[current_node] + heuristic(current_node, jumppoint);
                    double f = g + h;
                    path_cost[jumppoint] = g;
                    parents[jumppoint] = current_node;
                    open.push({f, jumppoint});
                    visited.push_back(jumppoint);
                    if (jumppoint == goal) {
                        break;
                    }
                }
            }
        }
    }
    
    return -1;
}

void JPS::visualize_grid(double cost) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    // Set the size of grid
    int cell_size = 20;
    int img_width = cols * cell_size;
    int img_height = rows * cell_size;

    // Create video file
    // AVI Pattern
    // VideoWriter video("JPS_animation.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 100, Size(img_width, img_height));
    // MP4 Pattern
    VideoWriter video("JPS_animation.mp4", VideoWriter::fourcc('m', 'p', '4', 'v'), 100, Size(img_width, img_height));
    
    // Create image for each frame
    Mat img(img_height, img_width, CV_8UC3, Scalar(255, 255, 255));
    // Title and Cost
    std::string title = "JPS";
    putText(img, title, Point(550, 40), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 0, 0), 2);
    std::string cost_text = "Cost: " + std::to_string(cost);
    putText(img, cost_text, Point(500, 80), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 0, 0), 2);

    // Draw Obstacles
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            if (grid[i][j] == 1) {
                rectangle(img, Point(j * cell_size, i * cell_size),
                          Point((j + 1) * cell_size, (i + 1) * cell_size),
                          Scalar(0, 0, 0), FILLED);
            }
        }
    }

    // Draw start and goal point
    rectangle(img, Point(start.second * cell_size, start.first * cell_size),
            Point((start.second + 1) * cell_size, (start.first + 1) * cell_size),
            Scalar(0, 255, 0), FILLED);

    rectangle(img, Point(goal.second * cell_size, goal.first * cell_size),
            Point((goal.second + 1) * cell_size, (goal.first + 1) * cell_size),
            Scalar(0, 255, 255), FILLED);

    // Draw visited areas
    for (size_t i=1;i<visited.size()-1;++i) 
    {
        const auto& node = visited[i];
        rectangle(img, Point(node.second * cell_size, node.first * cell_size),
        Point((node.second + 1) * cell_size, (node.first + 1) * cell_size),
        Scalar(128, 128, 128), FILLED);
        
        video.write(img);
    }

    // Draw path
    for (size_t i = 1; i < path.size(); ++i) 
    {
        Point p1(path[i - 1].second * cell_size + cell_size / 2,
                path[i - 1].first * cell_size + cell_size / 2);
        Point p2(path[i].second * cell_size + cell_size / 2,
                path[i].first * cell_size + cell_size / 2);
        line(img, p1, p2, Scalar(0, 0, 255), 2);

        video.write(img);
    }

    video.release();
    imwrite("JPS_result.png", img);
    imshow("JPS", img);
    waitKey(0);
    destroyAllWindows();
}