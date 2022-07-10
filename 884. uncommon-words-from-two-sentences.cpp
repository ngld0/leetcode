class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> res; // save result to return;
        unordered_map<string, int> mm; //using map to check each word; cause of space complexity O(n) 
        string word = ""; 
        for(int i = 0; i < s1.length();i++){ // Time O (n) for each word of s1 string
            if(s1[i]==' '){ // the space, then count  the previous word;
                mm[word]++;
                word = "";
            }else {
                word += s1[i];
            }
        }
        if (word != ""){ // count the last word; because the end of line  without space;
            mm[word]++;
            word = "";
        }
        
        for(int i = 0 ; i < s2.length();i++){ // Time O(m) search words of s2 string;
            if(s2[i]==' ' ){ 
                if(mm[word] != 0) // if we already meet the word, then we should ignore it;
                    mm[word] = -1; 
                else 
                    mm[word]++; // if the word is new; then count the word of s2 string
                word = "";
            }else {
                word += s2[i];
            }
        }
        if (word != "" ){ //checking for the last word of string s2;
            if( mm[word] != 0 ) 
                mm[word]=-1;
            mm[word]++;
        }
        
        for(auto s : mm){ // come out the result;
            if(s.second == 1 ){
                res.push_back(s.first);
            }
        }
        return res;
    }
};
