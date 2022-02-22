class Solution {
public:
    int countEven(int num) {
        int cnt = 0;
        for(int i = 2; i <= num;i++){
            if(digitSumEven(i)) cnt++;
        }
        return cnt;
        
    }
    bool digitSumEven(int num){
        int sum = 0;
        while(num){
            
            sum += num %10;
            num /= 10;
        }
        return sum %2 ==0 ? true:false;
    }
};
