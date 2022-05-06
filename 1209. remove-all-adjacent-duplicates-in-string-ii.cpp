class Solution {
public:
    string removeDuplicates(string s, int k) {
       
        int i = 0, len = s.length();
        vector<int> count(len);
        for (int j = 0; j < len; ++j, ++i) {
            s[i] = s[j];
            count[i] = i > 0 && s[i - 1] == s[j] ? count[i - 1] + 1 : 1;
            if (count[i] == k) i -= k;
        }
        return s.substr(0, i);
        
    }
};
