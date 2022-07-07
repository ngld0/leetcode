class Solution {
public:
    bool isPerfectSquare(int num) {
       if(num <=1) return true;
        if(num < 4) return false;
        for(int i = 1;i<= num/2 && i < 46341;i++){
            if(i*i == num) return true;
            if(i*i>num) return false;
        }
        return false;
    }
};
