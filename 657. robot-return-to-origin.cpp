class Solution {
public:
    bool judgeCircle(string moves) {
        int up = 0, left = 0;
        for(auto move:moves){
            if(move == 'U') up++;
            if(move == 'D') up--;
            if(move == 'L') left++;
            if(move == 'R') left--; 
        }
        return up == 0 && left == 0;
    }
};
