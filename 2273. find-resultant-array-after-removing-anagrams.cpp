class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        if(n<=1)  return words;
        for(int i = 1;i<words.size();i++){
            int j = i-1;
            if(anagram(words[i],words[j])) {
                words.erase(words.begin()+i);   
                i--;
            }
        }
        return words;
        
    }
    bool anagram(string s, string t){
        /*
        //using sort
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s == t) return true;
        return false;
        */
        //using  pointer
        vector<int> count(26);
        for(int i = 0 ; i < s.size();i++){
            count[s[i]-'a']++;
        }
        for(int i = 0; i<t.size();i++){
            count[t[i]-'a']--;
        }
        for(int i = 0 ; i < 26;i++){
            if(count[i] != 0) return false;
        }
        return true;
        
    }
};
