class Solution {
public:
    int dp[51][51][51];
    
    int mode = 1e9 + 7;
    
    int dfs(int m, int n, int maxMove, int i, int j)
    {
        if(i >= m or j >= n or i < 0 or j < 0)
            return 1;
        
        if(maxMove == 0)
            return 0;
        
        if(dp[i][j][maxMove] != -1)
            return dp[i][j][maxMove];
        
        int w = dfs(m,n,maxMove-1,i+1,j);
        
        int x = dfs(m,n,maxMove-1,i,j+1);
        
        int y = dfs(m,n,maxMove-1,i-1,j);
        
        int z = dfs(m,n,maxMove-1,i,j-1);
        
        return dp[i][j][maxMove] = ((((w + x)%mode + y)%mode + z)%mode)%mode;
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        
        return dfs(m,n,maxMove,startRow,startColumn);
        
    }
};
