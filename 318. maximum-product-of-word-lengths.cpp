class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int n = words.size(), ans = 0;
        vector<int> mm(n);
        for(int i = 0; i < n;i++){
            int len =  words[i].length();
            for(int j = 0; j < len;j++){
                mm[i] |= 1 << (words[i][j] -'a'); //hashing each char in words[i]
            }
            for(int j = 0; j < i;j++){
                if((mm[i] & mm[j]) == 0){ // whether two words[i] and words[j] are sharing common letters?
                    int product = words[i].length() * words[j].length();
                    ans = ans > product ? ans: product;
                }
            }
        }
        return ans;
    }
    /*
    //Timeout solution
    int maxProduct(vector<string>& words) {
        
        
        int n = words.size(), ans = 0;
        vector<vector<int>> dp(words.size(), vector<int>(26));
        for(int i = 0; i<n;i++){
            int len = words[i].length();
            for(int j  = 0 ; j< len;j++){
                dp[i][words[i][j]-'a']++;
            }
        }
        
        for(int i = 0; i <n-1;i++){
            for(int j = i+1;j<n;j++){
                if(!sharing(i, j, dp)){
                    int product = words[i].length() * words[j].length();
                    ans = ans>product?ans:product;
                }
            }
        }
        return ans;
    }
    bool sharing(int idx1, int idx2,vector<vector<int>> dp){
        for(int i = 0 ;i<26;i++){
            if(dp[idx1][i]>0 && dp[idx2][i]>0) return true;
        }
        return false;
    }
    */
};
