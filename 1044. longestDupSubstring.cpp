class Solution {
public:
    string longestDupSubstring(string str) {
        string_view ans;
        unordered_set<string_view> s;
        int l = 0;
        int h = str.size();
        int m;
        while(l<=h)
        {
            bool flag = 0;
            m = l+(h-l)/2;
            auto t = string_view(str);
            for(int i=0;i<str.size()-m+1;++i)
            {
                auto x = t;
                x.remove_prefix(i);
                x.remove_suffix(str.size()-m-i);
                auto y = s.insert(x);
                if(y.second != true)
                {
                    flag = 1;
                    ans = x;
                    break;
                }
            }
            if(flag)
                l = m+1;
            else h = m-1;
        }
        return string(ans);
    }
};
/*
Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.

Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".

 

Example 1:

Input: s = "banana"
Output: "ana"
Example 2:

Input: s = "abcd"
Output: ""
 

Constraints:

2 <= s.length <= 3 * 104
s consists of lowercase English letters.
*/
