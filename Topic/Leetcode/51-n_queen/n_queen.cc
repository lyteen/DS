#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int n;
public:
    vector<vector<string>> solveNQueens(int n) {
        // col, diag1, diag2
        // diag1 = row - col, diag2 = row + col
        vector<int> queens(n);
        vector<int> col(n);
        vector<int> diag1(2 * n - 1);
        vector<int> diag2(2 * n - 1);
        vector<vector<string>> ans;
        auto func = [&](auto && func, int row) -> void
        {
            if(row == n)
            {   
                vector<string> str(n);
                for(int i = 0; i < n; i++)
                {
                    str[i] = string(queens[i], '.') + 'Q' + string(n - 1 - queens[i], '.'); // 0 th not note the str
                }
                ans.push_back(str);
                return;
            }
            for(int c = 0; c < n; c++) // recursive each situation
            {
                if(!col[c] && !diag1[row - c + n - 1] && !diag2[row + c])
                {
                queens[row] = c;
                col[c] = diag1[row - c + n - 1] = diag2[row + c] = true;
                func(func, row + 1);
                col[c] = diag1[row - c + n - 1] = diag2[row + c] = false;
                }
            }
        };
        func(func, 0);
        return ans;
    }
};

int main()
{
    Solution sol;
    int n = 4;
    vector<vector<string>> ans;
    ans = sol.solveNQueens(n);
    for(auto a:ans)
    {   
        for(auto i:a)
        {
            cout << i << "\n";
        }
        cout << '\n';
    }
    return 0;
}