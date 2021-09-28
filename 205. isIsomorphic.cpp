class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int size = s.size();
        int sT[128] = {0},tT[128] = {0};
        for(int i = 0 ; i < size;i++){
            if(sT[s[i]] != tT[t[i]])
                return false;
            sT[s[i]] = i + 1;
            tT[t[i]] = i + 1;
        }
        
        return true;
    }
};
