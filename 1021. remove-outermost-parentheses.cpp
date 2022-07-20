class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0; // using cnt to count the oepn Round Brackets or open Parentheses
        string res;
        for (char c : s) {
            if (c == '(') { // check it is open brakcets
                if (cnt != 0) {
                    res += '(';
                }
                cnt++;
            } else { // if it is close brackets
                --cnt;
                if (cnt != 0) {
                    res += ')';
                }
            }
        }
        return res;
    }
};
