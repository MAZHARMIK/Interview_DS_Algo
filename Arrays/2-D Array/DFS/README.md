<img src="https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/icon.png?raw=true" align="right" width="90" /><a href="https://github.com/MAZHARMIK"><img src="https://github.blog/wp-content/uploads/2008/12/forkme_left_orange_ff7600.png?resize=149%2C149" alt="Fork me on GitHub" width="110" align="left"></a>

<div align="center">

# 🧭 Arrays / 2-D Array / DFS

**Grid traversal problems solved with Depth-First Search, curated for coding interviews.**

![Language](https://img.shields.io/badge/language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Topic](https://img.shields.io/badge/topic-DFS-ff7600?style=for-the-badge)
![Problems](https://img.shields.io/badge/problems-7-2ea44f?style=for-the-badge)
![Platform](https://img.shields.io/badge/platform-LeetCode-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)

[⬅ Back to main repo](https://github.com/MAZHARMIK/Interview_DS_Algo) · [⭐ Star](https://github.com/MAZHARMIK/Interview_DS_Algo) · [🍴 Fork](https://github.com/MAZHARMIK/Interview_DS_Algo/fork)

<img src="https://he-s3.s3.amazonaws.com/media/uploads/9fa1119.jpg" width="600" alt="DFS illustration" />

</div>

---

## 📚 Problem List

| # | Problem | LeetCode | Difficulty | Solution |
|:-:|:--------|:--------:|:----------:|:--------:|
| 1 | **Pacific Atlantic Water Flow** | [417](https://leetcode.com/problems/pacific-atlantic-water-flow/) | 🟡 Medium | [C++/Java](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/2-D%20Array/DFS/Pacific%20Atlantic%20Water%20Flow.cpp) |
| 2 | **Longest Increasing Path in a Matrix** | [329](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/) | 🔴 Hard | [C++/Java](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/2-D%20Array/DFS/Longest_Increasing_Path_in_a_Matrix.cpp) |
| 3 | **Number of Closed Islands** | [1254](https://leetcode.com/problems/number-of-closed-islands/) | 🟡 Medium | [C++/Java](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/2-D%20Array/DFS/Number%20of%20Closed%20Islands.cpp) |
| 4 | **Number of Enclaves** | [1020](https://leetcode.com/problems/number-of-enclaves/) | 🟡 Medium | [C++/Java](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/2-D%20Array/DFS/Number%20of%20Enclaves.cpp) |
| 5 | **Regions Cut By Slashes** | [959](https://leetcode.com/problems/regions-cut-by-slashes/) | 🟡 Medium | [C++/Java](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/2-D%20Array/DFS/Regions%20Cut%20By%20Slashes.cpp) |
| 6 | **Minimum Number of Days to Disconnect Island** | [1568](https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/) | 🔴 Hard | [C++/Java](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/2-D%20Array/DFS/Minimum%20Number%20of%20Days%20to%20Disconnect%20Island.cpp) |
| 7 | **Count Unguarded Cells in the Grid** | [2257](https://leetcode.com/problems/count-unguarded-cells-in-the-grid/) | 🟡 Medium | [C++/Java](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/2-D%20Array/DFS/Count%20Unguarded%20Cells%20in%20the%20Grid.cpp) |
| 7 | **Count Islands With Total Value Divisible by K** | [3619](https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k) | 🟡 Medium | [C++/Java](https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/2-D%20Array/DFS/Count%20Islands%20With%20Total%20Value%20Divisible%20by%20K.cpp) |

> **Legend:** 🟢 Easy · 🟡 Medium · 🔴 Hard

---

## 🧠 Common DFS-on-Grid Patterns

| Pattern | When to use it | Problems |
|:--------|:---------------|:---------|
| **Boundary-first flood fill** | Cells touching the border behave differently from interior ones | 1254, 1020 |
| **Multi-source / reverse DFS** | Easier to start from the destination than from every source | 417 |
| **DFS + memoization** | Overlapping subproblems on a DAG-like grid | 329 |
| **Connected components counting** | Need the number of islands / regions | 959, 1568 |
| **Directional scan / marking** | Propagate effects along rows and columns | 2257 |

### 🔁 Reusable Template

```cpp
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(vector<vector<int>>& grid, int r, int c) {
    int m = grid.size(), n = grid[0].size();
    if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] != 1) return;

    grid[r][c] = 2;                       // mark visited
    for (int d = 0; d < 4; d++)
        dfs(grid, r + dx[d], c + dy[d]);
}
```

---

## 🚀 How to Use This Folder

1. Open a problem on LeetCode and try it on your own first.
2. Compare your approach with the solution in this folder.
3. Read the C++ solution and note the time and space complexity.
4. Re-solve it after a few days without looking.

---

<div align="center">

**Found this helpful?** Give the repo a ⭐ and share it with a friend preparing for interviews.

Made with ❤️ by [MAZHARMIK](https://github.com/MAZHARMIK)

</div>
