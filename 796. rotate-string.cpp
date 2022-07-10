class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!= goal.length()) 
            return false;
        if(s == goal) return true;
        int n = goal.length();
        string a = "";
        for(int i = 0 ; i < n;i++){
            a = s.substr(i) + s.substr(0,i);
            if(a == goal) return true;
        }
        
        return false;
    }
};
