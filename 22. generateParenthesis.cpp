class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(0,0,res,"",n);
        return res;
    }
    
    void helper(int l, int r, vector<string> &res, string s, int n){
        
        if(l==n && r==n){
            res.push_back(s);
            return;
            
        }
        if(l<n){
            helper(l+1,r,res, s +'(',n);
        }
        if(r < l){
            helper(l,r+1,res, s +')',n);
        }
    }
};
/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/
