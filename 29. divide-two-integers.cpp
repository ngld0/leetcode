class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        while (dvd >= dvs) {
            long temp = dvs, m = 1;
            while (temp << 1 <= dvd) {
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            ans += m;
        }
        return sign * ans;
    }
    /*
    // sol 20220530
    int divide(int dividend, int divisor) {
        int res=0;
        if(dividend == INT_MIN && divisor == -1) 
            return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) 
            return INT_MIN;
        
        long int divd = abs(dividend), divr = abs(divisor);
        
        while(divr<=divd) {
            long int mul = divr, tmp=1;
            while(mul <= divd - mul) {
                mul += mul;
                tmp += tmp;
            }
            res += tmp;
            divd -= mul;
        }
        
        if((dividend <0 && divisor>0) || (dividend >0 && divisor<0)) 
            return -res;
        
        return res;
    }
    */
};
/*
The key observation is that the quotient of a division is just the number of times that we can subtract the divisor from the dividend without making it negative.

Suppose dividend = 15 and divisor = 3, 15 - 3 > 0. We now try to subtract more by shifting 3 to the left by 1 bit (6). Since 15 - 6 > 0, shift 6 again to 12. Now 15 - 12 > 0, shift 12 again to 24, which is larger than 15. So we can at most subtract 12 from 15. Since 12 is obtained by shifting 3 to left twice, it is 1 << 2 = 4 times of 3. We add 4 to an answer variable (initialized to be 0). The above process is like 15 = 3 * 4 + 3. We now get part of the quotient (4), with a remaining dividend 3.

Then we repeat the above process by subtracting divisor = 3 from the remaining dividend = 3 and obtain 0. We are done. In this case, no shift happens. We simply add 1 << 0 = 1 to the answer variable.

This is the full algorithm to perform division using bit manipulations. The sign also needs to be taken into consideration. And we still need to handle one overflow case: dividend = INT_MIN and divisor = -1.
*/
/*
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, assume that your function returns 231 − 1 when the division result overflows.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = truncate(-2.33333..) = -2.
Example 3:

Input: dividend = 0, divisor = 1
Output: 0
Example 4:

Input: dividend = 1, divisor = 1
Output: 1
 

Constraints:

-231 <= dividend, divisor <= 231 - 1
divisor != 0
*/
