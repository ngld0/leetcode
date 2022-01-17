class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<int> p_map (26, 0);
        unordered_map<string,int> s_map;
        int i=0, n = pattern.size();
        istringstream ss(s);
        string token;
        for(string token; ss >> token; ++i) {
            if(i == n || p_map[pattern[i]-'a'] != s_map[token]) return false;
            p_map[pattern[i]-'a'] = s_map[token] = i+1;
        }
        
        return i == n;
    }
};
