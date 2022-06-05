class Solution {
public:
  // sol 1
      string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n = messages.size();
        unordered_map<string, int> cnt;
        for(int i = 0 ; i< n;i++){
            stringstream w(messages[i]);
            string word;
            while(w>>word){
                cnt[senders[i]]++;
            }
        }
        /*
        loop all element of map by the following ways:
        1. traditional
        unordered_map<string, int>::iterator it;
        for(it = cnt.begin(); it != cnt.end();it++){
            cout<< it->first << "---" << it->second <<endl;
        }
        2. C++ 11
        for (auto const& it : cnt){
            cout<< it.first << "---" << it.second <<endl;
        }  
        3.  C++ 17
        for (auto const& [key, val] : cnt) {
            cout<< key << "---" << val <<endl;
        } 
        */
        int mcount = 0;
        string muser = "";
        for(auto const& [user, count]:cnt){
            if(mcount < count){ // searching for max count;
                mcount = count;
                muser = user;
            }else if(mcount == count && user >muser) //  lexicographically largest name
                muser = user;
        }
        return muser;
        
    }
  /*
     // sol 2.
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string, int> m;
        int mx_words = 0;
        for(int i = 0;i < messages.size();i++){
            m[senders[i]] += count(messages[i].begin(), messages[i].end(), ' ')  +1;
            
            mx_words = max(mx_words, m[senders[i]]);
            
        }
        string ans;
        for(auto data : m){
            ans = data.second == mx_words ? data.first : ans;
        }
        
        return ans;
        
    }
  */
 

  
};
