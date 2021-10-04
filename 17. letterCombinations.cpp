class Solution {
public:
    vector<string> letterCombinations(string digits) {
        //digits empty return empty
        if(digits.empty()) return {};
        
        vector<string> res;
        // 0 -> 9
        vector<string> dic{"", "", "abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        DFS(digits, dic, 0, "", res);
        
        return res;
    }
    
    void DFS(string &digits, vector<string> & dic, int level, string out, vector<string> & res){
        if(level == digits.size())
        {
            res.push_back(out);
            return;
        }        
        string str = dic[digits[level] - '0'];
        for(int i =0; i< str.size();i++){
            
            DFS(digits, dic, level +1, out+str[i], res);
        }
    }
};
/***
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
***/
