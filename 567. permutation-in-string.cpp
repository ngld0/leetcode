class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s2_vec(26), s1_vec(26);
        
        for(char c1 : s1) {
            s1_vec[c1 - 'a']++;
        }
            
        
        for(int i = 0; i < s2.size(); i++) {
            
            s2_vec[s2[i] - 'a']++;
            //substring, each character is not seperate by another character out of s1
            // decrease the character out of s1.size range
            if(i >= s1.size()) {
                s2_vec[s2[i - s1.size()] - 'a']--;
            } 
            // check the size first and using std::equal to compare two vector.
            if(s1_vec == s2_vec) return true;
        }
        return false;
    }
};
/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 10^4
s1 and s2 consist of lowercase English letters.
*/
