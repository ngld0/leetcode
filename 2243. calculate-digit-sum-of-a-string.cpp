class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.length();
        if(n <= k) return s;
        string tt = "";
        int sum = 0;
        for(int i = 0; i < n;i++){
            if(i != 0 && i % k == 0){
                tt += to_string(sum);
                sum = 0;
            }
            sum += s[i]-'0'; 
        }
        tt += to_string(sum);
        return digitSum(tt, k);
    }
};
