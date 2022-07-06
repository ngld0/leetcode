class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        int mm = 0;
        while(columnNumber != 0){
            columnNumber -= 1;
            mm = columnNumber % 26;
            char c = 'A'+ mm;
            res = c + res;
            columnNumber /= 26;
        }
        return res;
        
    }
};
