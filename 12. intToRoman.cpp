class Solution {
public:
    string intToRoman(int num) {
        //sol1
//         string res = "";
//         vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
//         //C can be placed before D (500) and M (1000) to make 400 and 900.
//         //X can be placed before L (50) and C (100) to make 40 and 90. 
//         //I can be placed before V (5) and X (10) to make 4 and 9. 
//         vector<string> str{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
//         for (int i = 0; i < val.size(); i++) {
//             while (num >= val[i]) {
//                 num -= val[i];
//                 res += str[i];
//             }
//         }
//         return res;
        //Sol 2
        string res = "";
        while(num>=1000){
            res = res + "M";
            num-=1000;
        }

        while(num>=900){
            res = res + "CM";
            num-=900;
        }

        while(num>=500){
            res = res + "D";
            num-=500;
        }

        while(num>=400){
            res = res + "CD";
            num-=400;
        }

        while(num>=100){
            res = res + "C";
            num-=100;
        }

        while(num>=90){
            res = res + "XC";
            num-=90;
        }

        while(num>=50){
            res = res + "L";
            num-=50;
        }

        while(num>=40){
            res = res + "XL";
            num-=40;
        }

        while(num>=10){
            res = res + "X";
            num-=10;
        }

        while(num>=9){
            res = res + "IX";
            num-=9;
        }

        while(num>=5){
            res = res + "V";
            num-=5;
        }

        while(num>=4){
            res = res + "IV";
            num-=4;
        }

        while(num>=1){
            res = res + "I";
            num-=1;
        }
        return res;
    }
};
/***
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

 

Example 1:

Input: num = 3
Output: "III"
Example 2:

Input: num = 4
Output: "IV"
Example 3:

Input: num = 9
Output: "IX"
Example 4:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= num <= 3999
***/
