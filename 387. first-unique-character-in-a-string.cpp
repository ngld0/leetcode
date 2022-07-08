class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        unordered_map<int, int> mm;
        for(char c: s){
            mm[c]++;
        }
        for(int i = 0 ; i <n;i++){
            if(mm[s[i]]==1) return i;
            
        }
        return -1;
    }
};
