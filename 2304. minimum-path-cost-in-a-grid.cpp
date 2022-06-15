class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        //int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        
        dp[0] = grid[0];
        
        for(int i = 1; i < m;i++){
            for(int j = 0 ; j < n;j++){
                for(int k = 0; k < n; k++){
                    dp[i][k] = min(dp[i][k], grid[i][k] + dp[i-1][j]+moveCost[grid[i-1][j]][k]);
                }
            }
        }
        
        int ans = dp[m-1][0];
        for(int i = 0 ; i < dp[m-1].size();i++){
            ans = min(ans, dp[m-1][i]);
        }
        
        return ans;
        
    }
};
