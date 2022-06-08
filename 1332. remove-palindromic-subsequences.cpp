class Solution {
public:
    int removePalindromeSub(string s) {
        int i = 0, j = s.length() -1;
        if(s == "") return 0;
        for(; i <j && j >= 0; i++, j--)
            if(s[i]!=s[j]) return 2;
        
        return 1;
    }
};
