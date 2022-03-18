class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ret="";
        int lastPos[26] = {}; 
        
        bool added[26] = {};  
        for (int i = 0; i < s.size(); i++)
        {
            lastPos[s[i] - 'a'] = i;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (added[s[i] - 'a']) continue;
            
            while ( !ret.empty() && ret.back() > s[i] && lastPos[ret.back() - 'a'] > i)
            {
                added[ret.back() - 'a'] = false;
                ret.pop_back();
            }
            ret.push_back(s[i]);
            
            added[s[i] - 'a'] = true;
        }
        return ret;
        
    }
};
