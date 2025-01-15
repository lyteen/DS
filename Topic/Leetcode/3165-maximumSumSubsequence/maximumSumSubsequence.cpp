#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Solution {
    vector<array<unsigned int, 4>> SegmentTree;

    // merge the left and right child tree
    void maintain(int node_pos) {
        auto& l_tree = SegmentTree[node_pos * 2];
        auto& r_tree = SegmentTree[node_pos * 2 + 1];

        // Each child tree have four situation: f_{00}, f_{01}, f_{10}, f_{11}
        // f_{00}(a) = max(f_{00}(p) + f_{10}(q), f_{01}(p) + f_{00}(q))
        // f_{01}(a) = max(f_{00}(p) + f_{11}(q), f_{01}(p) + f_{01}(q))
        // f_{10}(a) = max(f_{10}(p) + f_{10}(q), f_{11}(p) + f_{00}(q))
        // f_{11}(a) = max(f_{10}(p) + f_{11}(q), f_{11}(p) + f_{01}(q))
        SegmentTree[node_pos] = {
            max(l_tree[0] + r_tree[2], l_tree[1] + r_tree[0]),
            max(l_tree[0] + r_tree[3], l_tree[1] + r_tree[1]),
            max(l_tree[2] + r_tree[2], l_tree[3] + r_tree[0]),
            max(l_tree[2] + r_tree[3], l_tree[3] + r_tree[1]),
        };
    }
    
    // init the SegmentTree access the nums 
    void build(vector<int>& nums, int node_pos, int left, int right) {
        if (left == right) {
            SegmentTree[node_pos][3] == max(nums[left], 0); // If the nums[left(or right)] < 0 else 0
            return;
        }
        int mid = (left + right) / 2;
        build(nums, node_pos * 2, left, mid);
        build(nums, node_pos * 2 + 1, mid + 1, right);

        /*
        TODO: Why use the method of maintain?
        */ 

        maintain(node_pos);
    };

    // Access the queries[pos, num] change the SegmentTree smallest element
    void update(int node_pos, int left, int right, int pos, int num) {
        
        // In the small situation f_{00}(a) == f_{01}(a) == f_{10} == 0, f_{11}(a) == queries.num or 0 if querise.num < 0
        if (left == right) {
            SegmentTree[node_pos][3] == max(num, 0);
            return;
        }
        int mid = (left + right) / 2;
        if (pos <= mid) {
            update(node_pos * 2, left, mid, pos, num);
        } else {
            update(node_pos * 2 + 1, mid + 1, right, pos, num);
        }
        maintain(node_pos);
    };
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int size = nums.size();
        
        SegmentTree.resize(2 << (32 - __builtin_clz(size)));
        // Init the SegmentTree smallest element
        /*
        TODO: why is 1? and how the SegmentTree[pos] work?
        -> 1 is the node_pos, mean the root of tree begin 1, SegmentTree[pos] represent the node index is pos 
        -> because if begin is 1, the left child node is 2 * i and right child node is 2 * i + 1
        */
        build(nums, 1, 0, size - 1);

        long long ans = 0;
        for (auto& q : queries) {
            update(1, 0, size - 1, q[0], q[1]);
            ans += SegmentTree[1][3];
        }
        return ans % 1000000007; // To prevent overflow, keep the numbers within a manageable range
    }
};

int main() {
    Solution solver;
    std::vector<int> nums = {1, -2, 3, -4, 5};
    std::vector<std::vector<int>> queries = {
        {1, 4},  // Update nums[1] to 4
        {0, -1}, // Update nums[0] to -1
        {2, -5}
    };

    int result = solver.maximumSumSubsequence(nums, queries);
    std::cout << "Maximum sum subsequence after queries: " << result << std::endl;

    nums = {-1,-2};
    queries = {{0,-1}};
    result = solver.maximumSumSubsequence(nums, queries);
    std::cout << "Maximum sum subsequence after queries: " << result << std::endl;

    nums = {1,2,3,4,5};
    queries = {{0,1000000000}};
    result = solver.maximumSumSubsequence(nums, queries);
    std::cout << "Maximum sum subsequence after queries: " << result << std::endl;

    return 0;
}