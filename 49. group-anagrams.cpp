class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> map;
        for(auto str: strs){
            string ss = str;
            sort(ss.begin(), ss.end());
            map[ss].push_back(str);
        }
        for(auto mm : map){
            
            ret.push_back(mm.second);
        }
        return ret;
    }
};
