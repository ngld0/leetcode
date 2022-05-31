class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.size()) return false;
        
        unordered_set<string> ss;
        
        for (int i = 0; i <= s.size()-k; i++)
            ss.insert(s.substr(i, k));
        
        return ss.size() == pow(2, k);
    }
};
