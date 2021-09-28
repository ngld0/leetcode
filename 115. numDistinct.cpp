class Solution {
public:
    // Fail test case: time limited!!!!
//     int numDistinct(string s, string t) {
//         int res = 0, i =0, j= 0, n = s.size(), m = t.size();
        
//         if(n < m) return 0;
        
//         if(m == 0) return 1;
        
//         for(i = 0 ;i < n ; i++){
            
//             if(s[i] == t[0]){
//                 string ssub = s.substr(i+1);
//                 string tsub = t.substr(1);
//                 res += numDistinct(ssub,tsub );
                
                
//             }
//         }
//         return res;
//     }
    
    //Using dynamic Programing
    int numDistinct(string s, string t) {
        int res = 0, i, j, n = s.size(), m = t.size();
        if(m==0) return 1;
        
        if(n < m) return 0;
        
        if(m == n) return s==t;
        
        vector<vector<long>> dp(m+1, vector<long>(n + 1));
        
        for(i = 0; i < n;i++) dp[0][i] =1;
        
        for(int i = 1; i <= m;i++){
            for(int j = 1 ; j <= n ; j++){
                
                dp[i][j] = dp[i][j-1] +(t[i-1] == s[j-1]?dp[i-1][j-1]:0);
            }
            
        }
        return dp[m][n];
    }
};
/***
Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

It is guaranteed the answer fits on a 32-bit signed integer.

 

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
babgbag
babgbag
babgbag
babgbag
babgbag
 

Constraints:

1 <= s.length, t.length <= 1000
s and t consist of English letters.

***/
