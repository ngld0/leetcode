class Solution {
public:

    /*
    bool isSub(string s, string w){
        int j = 0;
        for (int i = 0; i < w.length();i++){
            if(j>= s.length()) return false;
            
            while(w[i] != s[j] && j < s.length()) j++;
            j++;
        }
        if(j > s.length()) return false;
        return true;
    }
    
    //bruteforce: time limited!
    int numMatchingSubseq(string s, vector<string>& words) {
        int cnt = 0;
        for(int i = 0; i < words.size();i++){
            if(words[i].length() > s.length())continue;
            //cout<< isSub(s, words[i])<<endl;
            if(isSub(s, words[i])) cnt++;
            
        }
        return cnt;
        
    }    
    */
    /*
    bool isSub(vector<vector<int>> mm, string word){
        int tem = -1;
        
        for(char c : word) {
            
            vector<int> idx = mm[c - 'a'];
            
            auto it = upper_bound(idx.begin(), idx.end(), tem);
            
            if(it == idx.end()) {
                return false;
            } else {
                tem = *it;
            }
        }     
        return true;
    }    
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> mm(26);
        
        for(int i = 0; i < s.length(); i++) {
            mm[s[i] - 'a'].push_back(i);
        }
        
        int cnt = words.size();
        
        for(auto word : words) {
            int last = -1;
            if(!isSub(mm, word)){
                cnt--;
            }
        }
        return cnt;
    }
    */
    int numMatchingSubseq (string S, vector<string>& words) {
		vector<vector<int>> alpha (26);
		for (int i = 0; i < S.size (); ++i) alpha[S[i] - 'a'].push_back (i);
		int res = 0;

		for (const auto& word : words) {
			int x = -1;
			bool found = true;

			for (char c : word) {
				auto it = upper_bound (alpha[c - 'a'].begin (), alpha[c - 'a'].end (), x);
				if (it == alpha[c - 'a'].end ()) found = false;
				else x = *it;
			}

			if (found) res++;
		}

		return res;
	}
};
