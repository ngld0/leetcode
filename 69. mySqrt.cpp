class Solution {
public:
    int mySqrt(int x) {
        int res ;
        int left = 0, right = x;
        if (x== 1) return 1;
        if(x == 0 ) return 0;
        
        while(left <= right){
            
            long mid = (left + right) /2;
            long mul = mid * mid;
            //if (mul >= INT_MAX) right = mid -1;
            if (mid * mid > x) right = mid -1;
            else if(mul == x) return mid;
            else if(mid * mid < x){
                res =mid;
                left = mid+1;
            }
        }
        return res;
    }
};
/***

Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

 

Example 1:

Input: x = 4
Output: 2
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
 

Constraints:

0 <= x <= 231 - 1
***/
