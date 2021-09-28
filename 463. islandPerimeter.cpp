class Solution {
public:
    //https://leetcode.com/problems/island-perimeter/discuss/94992/java-9-line-solution-add-4-for-each-land-and-remove-2-for-each-internal-edge
    int islandPerimeter(vector<vector<int>>& grid) {
        //check grid 
        if(grid.empty()|| grid[0].empty()) return 0;
        int n = grid.size(), m = grid[0].size(), res = 0;
        //0(nm)
        for(int i = 0; i <n;i++){
            
            for(int j = 0;j<m;j++){               
                // working with grid[i][j] =1;
                if(grid[i][j] ==0) continue;
                //check first column or the previous column;
                if(j == 0||grid[i][j-1]==0) res++;
                //check last column or the following
                if(j == m-1 || grid[i][j+1] ==0) res++;
                //check last column or previous row at current column
                if(i == 0||grid[i-1][j]==0) res++;
                //check last row or the following row at current clumn
                if(i == n-1|| grid[i+1][j] == 0) res++;
            }
        }
        return res;
        
        
    }
};
/***
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example 1:


Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.
Example 2:

Input: grid = [[1]]
Output: 4
Example 3:

Input: grid = [[1,0]]
Output: 4
 

Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 100
grid[i][j] is 0 or 1.
There is exactly one island in grid.
***/
