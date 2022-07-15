class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        //cause time O(n^2)
        for(int i = 0; i < grid.size(); i++) // O (n)
            for(int j = 0; j < grid[0].size(); j++)// O(m)
                if(grid[i][j] == 1) // if the current grid == 1 then select the max areas;
                    area = max(area, dfs(grid, i, j));
        return area;
    }
    // using local variable to count the area; another way, we can use a global variable to count the area and the dfs return void;
    int dfs(vector<vector<int>>& grid, int i, int j){ // recursive function
        if( i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1){
            grid[i][j] = 0; // set the grid =0 if we traveled this grid
            return 1 + dfs(grid, i+1, j) + dfs(grid, i-1, j) + dfs(grid, i, j-1) + dfs(grid, i, j+1); // go through all neightboring grids and count the areas
        }
        return 0;
    }
};
