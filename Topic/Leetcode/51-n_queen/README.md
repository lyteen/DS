# **Topic**

n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

# **Args**

`vector<int>queens(n)`: save the location queens, n->row, queens(n)->col.

`vector<int>col(n), diag1(2 * n - 1), diag2(2 * n - 1)`: col->save col state; diag1->save main diagonal line; diag2->save secondary diagonal line.

`diag1` = `row - col`, `diag2` = `row + col`

# **Idea**

1. **recursive_function** -> recursive each location state
-> auto func = [&] (auto&& func, int r) {}
-> `[&]` implement lambda function capture variable from `{}`, `&&func` indicates allow the lambda to take itself as an argument (recursive function)