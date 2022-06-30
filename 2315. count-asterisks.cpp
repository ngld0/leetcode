class Solution {
public:
    int countAsterisks(string s) {
        int bars = 0;
        int  ans = 0;
        for(auto c:s){
            if(c == '*' && bars %2 == 0){ 
                ans++;
            }
            if(c == '|'){
                bars++;
            }
        }
        return ans;
    }
};
