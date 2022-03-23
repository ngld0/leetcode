class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ret = 0;
        while (target > startValue){
            if(target %2){
                
                target++;
            }else 
                target /=2;
            ret++;
        }
        return ret + startValue - target;
    }
};
