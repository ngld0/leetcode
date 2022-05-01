class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int sSize = s.size()-1;
        int tSize = t.size()-1;
        int countInS = 0, countInT = 0;
        while(sSize >= 0 || tSize >= 0){
            
            while(sSize >= 0 && (s[sSize] == '#'|| countInS > 0)) s[sSize--] == '#'? countInS++ :countInS--;
            
            while(tSize >= 0 && (t[tSize] == '#'|| countInT > 0)) t[tSize--] == '#'? countInT++ :countInT--;
            if(sSize < 0 || tSize < 0) return tSize == sSize;   
            if(s[sSize] != t[tSize]) return false;
            
            sSize--;
            tSize--;
        }
        return sSize == tSize ;
    }
};
