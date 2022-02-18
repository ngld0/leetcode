class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ret = "";
        int j =0;
        for(int i = 0; i< s.length();i++){
            if(j < spaces.size() && spaces[j] == i){
                ret += " ";
                j++;
            }
            ret += s[i];
            
        }
        return ret; 
    }
};
