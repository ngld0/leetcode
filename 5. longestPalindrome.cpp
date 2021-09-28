class Solution {
    private:
       int check(string s, int start, int end){
        while(start>=0 && end<s.length() && s[start]==s[end]){
            start--;
            end++;
        }
        return (end-start-1);
    }
    public: 
        string longestPalindrome(string s) {
        if( s.length()<1){
            return "";
        }

        int start=0;
        int res=0; // max length of longest palindrome till now

        for(int i=0;i<s.length();i++){
            //single char
            int len1=check(s,i,i);     

            // 2 character
            int len2 = check(s,i-1,i);    

            int len=max(len1,len2);
        
            if(len>res){
                res=len;
                start= i-len/2;
            }

        }
        return s.substr(start,res);

    }
};
/***
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
***/
