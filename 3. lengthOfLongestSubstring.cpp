class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       
        int res = 0, pivot = -1;
        unordered_map<char, int> mTem;
        for (int i = 0; i < s.size(); ++i) {
            if (mTem.count(s[i]) && mTem[s[i]] > pivot) {
                pivot = mTem[s[i]];  
            }
            mTem[s[i]] = i;
            res = max(res, i - pivot);            
        }
        return res;

    }
};
