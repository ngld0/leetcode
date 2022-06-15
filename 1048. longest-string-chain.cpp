class Solution {
public:
    int longestStrChain(vector<string>& words) {
        //using dp<string, int> to save the word, and count their predecessor chain
        unordered_map<string, int> dp;
        int ans = 1;
        
        sort(words.begin(),words.end(), [](string a, string b){
            return a.length() < b.length();
        });
        for(int i = 0; i < words.size();i++){
            dp[words[i]] = 1;
            
            //checking the predecssor word;
            for(int j  = 0 ; j < words[i].length();j++){
                // using tmp string to save the string exept the character j;
                // if dp contain tmp then, we have predecessor of this words in dp;
                string tmp = words[i].substr(0, j) + words[i].substr(j+1, words[i].length());
                if(dp.find(tmp) != dp.end()){
                    dp[words[i]] = dp[tmp] + 1;
                    ans = max(dp[words[i]], ans);
                }
            }
        }   
        
        return ans;
    }
 
    
};
