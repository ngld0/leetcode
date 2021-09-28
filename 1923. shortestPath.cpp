class Solution {
public:
    //Ref: https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1293-shortest-path-in-a-grid-with-obstacles-elimination/
    //BFS 
    //Time complexity: O(m*n*k)
    //Space complexity: O(m*n*k)
    int shortestPath(vector<vector<int>>& grid, int k) {
        const vector<int> dirs{0, 1, 0, -1, 0};
        const int n = grid.size();
        const int m = grid[0].size();
        vector<vector<int>> seen(n, vector<int>(m, INT_MAX));
        queue<tuple<int, int, int>> q; 
        int steps = 0;
        q.emplace(0, 0, 0);
        seen[0][0] = 0;
        while (!q.empty()) {
          int size = q.size();
          while (size--) {
            int cx, cy, co;
            tie(cx, cy, co) = q.front(); q.pop();         
            if (cx == m - 1 && cy == n - 1) return steps;
            for (int i = 0; i < 4; ++i) {
              int x = cx + dirs[i];
              int y = cy + dirs[i + 1];
              if (x < 0 || y < 0 || x >= m || y >= n) continue;
              int o = co + grid[y][x];
              if (o >= seen[y][x] || o > k) continue;            
              seen[y][x] = o;
              q.emplace(x, y, o);
            }
          }
          ++steps;
        }
        return -1;
    }
};
/*** 
You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

 

Example 1:

Input: 
grid = 
[[0,0,0],
 [1,1,0],
 [0,0,0],
 [0,1,1],
 [0,0,0]], 
k = 1
Output: 6
Explanation: 
The shortest path without eliminating any obstacle is 10. 
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
Example 2:

Input: 
grid = 
[[0,1,1],
 [1,1,1],
 [1,0,0]], 
k = 1
Output: -1
Explanation: 
We need to eliminate at least two obstacles to find such a walk.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 40
1 <= k <= m * n
grid[i][j] == 0 or 1
grid[0][0] == grid[m - 1][n - 1] == 0
***/
