class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        for (int i = 0 ; i < strs[0].size();i++){
            char same = strs[0][i];
            for(int j = 0;j < strs.size();j++){
                if(i >=strs[j].size() || same != strs[j][i])
                    return res;
                
            }
            res.push_back(same);
            
            
        }
        return res;
    }
};
