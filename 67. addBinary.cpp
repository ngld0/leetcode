class Solution {
public:
    //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Add Binary.

    string addBinary(string a, string b) {
        string res="";
        int n = a.length()-1, m = b.length()-1; 
        int carrier =0;
        while(n>=0 || m>=0 || carrier==1){
            carrier += n >= 0 ? a[n--] - '0' : 0;
            carrier += m >= 0 ? b[m--] - '0' : 0;
            res = char(carrier%2 + '0')+res;
            carrier /= 2;
        }
        return res;
    }
};
/***
Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
***/
