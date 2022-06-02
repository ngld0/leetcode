class Solution {
public:
    string removeDigit(string number, char digit) {
        int idx = 0, count = 0, n = number.size();
        for(int i = 0; i < n;i++){
            if(number[i] == digit){
                idx = i; // temporary index of the digit in str number
                count++;
            }
        } 
       // occurs once time then return;
        while(count > 1){
            for(int i = 0 ; i < n;i++){
              
                if(number[i] == digit && i + 1 < n && number[i+1] -'0' > number[i]-'0'){ // if the digit appear at first from right to left, and the next char is bigger than current then we should remove this digit in number to get max;
                    idx = i;
                    count = 1;
                    break;
                }else if(number[i] == digit) {
                    idx = i;
                }
                count--;
              // another sulution is use substr and compare two string, use a varible to save max string at first, and then compare in each iteration
            } 
        }
        
        number = number.substr(0,idx) + number.substr(idx+1,n - idx);
        
        return number;
        
    }
};
/* // sol-2
class Solution {
public:
string removeDigit(string number, char digit) {
    string res="";
    int n = number.length();
    int cnt = 0;
    // count the appear time of digit
    for(int i = 0 ; i < n; i++){
        if(number[i] == digit) cnt++;
    }
    bool ok = false;
    for(int i=0;i<n;i++){
        
        if(number[i] != digit || ok == true){
            res+=number[i];
        } else
        
        if(cnt > 1 && number[i] == digit && i+1 < n && number[i + 1] <= number[i] ){
            res+=number[i];
            cnt--;
        }else if(number[i] == digit)
            ok =true;
        cout<< res <<endl;
    }
    return res;
    }
};
*/
