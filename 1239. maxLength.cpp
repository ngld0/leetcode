//source: https://zxi.mytechroad.com/blog/searching/leetcode-1239-maximum-length-of-a-concatenated-string-with-unique-characters/
class Solution {
public:
    int maxLength(vector<string>& arr) {
               vector<int> a;
    
        for (const string& x : arr) {
          set<char> s(begin(x), end(x));
          if (s.size() != x.length()) continue;
          a.push_back(0);      
          for (char c : x) a.back() |= 1 << (c - 'a');      
        }

        int ans = 0;

        function<void(int, int)> dfs = [&](int s, int cur) {
          ans = max(ans, __builtin_popcount(cur));
          for (int i = s; i < a.size(); ++i)
            if ((cur & a[i]) == 0)
              dfs(i + 1, cur | a[i]);      
        };

        dfs(0, 0);
        return ans;
    }
};
/***
Given an array of strings arr. String s is a concatenation of a sub-sequence of arr which have unique characters.

Return the maximum possible length of s.

 

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All possible concatenations are "","un","iq","ue","uniq" and "ique".
Maximum length is 4.
Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible solutions are "chaers" and "acters".
Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
 

Constraints:

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lower case English letters.
***/
