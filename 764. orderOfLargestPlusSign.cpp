//Best Solution

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mine) {
        int dp[n+2][n+2][4];
        memset(dp,1,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
              dp[i][j][0]=1;dp[i][j][1]=1;dp[i][j][2]=1;dp[i][j][3]=1;
            }
        }
        for(int i=0;i<mine.size();i++){
            for(int j=0;j<4;j++)
            dp[mine[i][0]+1][mine[i][1]+1][j]=0;
        }
        
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<4;j++){
                dp[i][0][j]=0;dp[i][n+1][j]=0;
                dp[0][i][j]=0;dp[n+1][i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
              //  cout<<dp[i][j][0]<<" ";
                if(dp[i][j][0]!=0)
                    dp[i][j][0]+=dp[i-1][j][0];
                if(dp[i][j][1]!=0)
                    dp[i][j][1]+=dp[i][j-1][1];
            }
           // cout<<"\n";
        }
        int ans=0;
        for(int i=n;i>=1;i--){
            for(int j=n;j>=1;j--){
                if(dp[i][j][2]!=0)
                    dp[i][j][2]+=dp[i+1][j][2];
                if(dp[i][j][3]!=0)
                    dp[i][j][3]+=dp[i][j+1][3];
                //cout<<dp[i][j][0]<<" ";
                int mi=INT_MAX;
                for(int k=0;k<4;k++){
                    mi=min(mi,dp[i][j][k]);
                }
                //cout<<mi<<" ";
                ans=max(ans,mi);
            }
           // cout<<"\n";
        }
        return ans;
    }
};
// class Solution {
// public:
//     int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
//         int res = 0;
//         int cnt = 0;
        
//         vector<vector<int>> dp(n,vector<int>(n,0));
        
//         unordered_set<int> s;
        
//         for(auto mine:mines) s.insert(mine[0]*n +mine[1]);
        
//         for(int j = 0 ; j <n;j++){
            
//             cnt = 0;
//             //move up
//             for(int i=0;i<n;i++){
//                 cnt = s.count(i*n +j)?0:cnt+1;
//                 dp[i][j] = cnt;
//             }
//             cnt = 0;
//             //move down
//             for(int i=n-1;i >=0;i--){
                
//                 cnt = s.count(i*n +j)?0:cnt+1;
//                 dp[i][j]=min(dp[i][j],cnt);
                
//             }
//         }
        
//         for(int i = 0 ; i <n;i++){
            
//             cnt = 0;
//             //move left
//             for(int j=0;j<n;j++){
//                 cnt = s.count(i*n +j)?0:cnt+1;
//                 dp[i][j] = min(dp[i][j],cnt);
//             }
//             cnt = 0;
//             //move right
//             for(int j=n-1;j >=0;j--){
                
//                 cnt = s.count(i*n +j)?0:cnt+1;
//                 dp[i][j]=min(dp[i][j],cnt);
//                 res=max(res,dp[i][j]);
//             }
//         }
//         return res;
        
        
//     }
// };
