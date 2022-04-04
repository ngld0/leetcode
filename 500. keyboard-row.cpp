class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string first =  "qwertyuiop", second  = "asdfghjkl", third = "zxcvbnm";
        vector<string> ret;
        for(auto word: words){
            if(allInRow(word, first) || allInRow(word, second) || allInRow(word, third))
                ret.push_back(word);
        }
        return ret;
    }
    bool allInRow(string word, string row){
        
        for(auto c : word){
            char c_lower = tolower(c);
            if (row.find(c_lower) == std::string::npos)
                return false;
        }
        return true;   
    }
};
