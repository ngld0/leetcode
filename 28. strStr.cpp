class Solution {
public:
    int strStr(string haystack, string needle) {
 vector <int> lps (needle.size(), 0);
        int idx = 0;
        for (int i=1; i<needle.size();) {
            if (needle[i] == needle[idx]) {
                lps[i] = idx + 1;
                idx++;
                i++;
            } else {
                if (idx != 0) {
                    idx = lps[idx-1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        int i = 0;
        int j = 0;
        int res = 0;
        while (i < haystack.size() && j < needle.size()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                if (j != 0) {
                    j = lps[j-1];
                } else {
                    i++;
                }
            }
            res = i - j;
        }
        
        if (j == needle.size())
            return res;
        
        return -1;
    
    }
};
/***
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

 

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Example 3:

Input: haystack = "", needle = ""
Output: 0
 

Constraints:

0 <= haystack.length, needle.length <= 5 * 104
haystack and needle consist of only lower-case English characters.
***/
