class Solution {
public:
    // O(nlogn), space O(1) 
    /*
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(),t.end());
        return s == t;
    }
    */

    // O(n), O (1)
    bool isAnagram(string s, string t) {
        int mm[26] = {0};
        for(int i = 0 ; i < s.length();i++){
            mm[s[i]-'a']++;
            
        }
        for(int i = 0; i < t.length();i++){
            mm[t[i]-'a']--;
        }
        for(int i = 0 ; i<26;i++){
            if(mm[i]!= 0) return false;
        }
        return true;
    }
};
