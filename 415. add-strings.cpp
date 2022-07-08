class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.length()-1, m = num2.length()-1;
        int carry = 0;
        string res = "";
        while(n>=0&& m>=0){
            int sum = num1[n]-'0' + num2[m]-'0' + carry;

            char add = sum%10 +'0';
            carry = (sum) /10;
            res = add + res; 
            n--;
            m--;
        }

        while(n >= 0){
            int sum = num1[n]-'0' + carry;
            char add = sum%10 +'0';
            carry = (sum ) /10;
            res = add + res; 
            n--;

        }
        while(m >= 0){
            int sum = num2[m]-'0' + carry;
            char add = sum%10 +'0';
            carry = sum  /10;
            res = add + res; 

            m--;

        }
        cout<< carry<<endl;
        if(n == -1 && m == -1 && carry != 0){
            char add = (carry +'0');
            res =  add + res;
        }
        return res;
    }
};
