class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int slen = s.length();
        int count = 0;
        for(int i = 0 ; i < slen;i++){
            for(int j = 0;j < words.size();j++){
                if(s.substr(0,i+1) == words[j]){
                    count++;
                    words.erase(words.begin() + j);
                    j--;
                } 
            }
        }
        return count;
    }
};
