class Solution {
public:
    /*
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
    }*/
    // pattern solution. first, check whether sum of num degits are even?
    int countEven(int num) {
        int n = num, sum = 0;
        while(n){
            sum += n %10;
            n /= 10;
        }
        return (num - sum%2)/2;
    }
};
