class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int m = pref.length();
        int cnt = 0;
        for(int i = 0; i < words.size();i++){
            string sub = words[i].substr(0, m);
            if(sub == pref) cnt++; 
            
        }
        return cnt;
        
    }
};
