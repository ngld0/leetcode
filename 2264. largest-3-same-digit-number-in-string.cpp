class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int n = num.length(), mm = -1;
        for(int i = 0; i <= n -3;i++){
            if(num[i] == num[i+1] && num[i+1] == num[i+2] && (num[i]-'0') >mm){
                mm = (num[i]-'0');
                ans = num.substr(i, 3);
            }
        }
        return ans;
    }
};
