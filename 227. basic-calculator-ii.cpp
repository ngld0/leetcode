class Solution {
public:
    int calculate(string s) {
        int currentNumber = 0, lastNumber = 0, result = 0;
        if(s.size() == 0) {
            return result;
        }
        char operand = '+';
        int temp;
        for(int i = 0; i<s.size(); i++) {
            char c = s[i];
            if(isdigit(c)) {
                currentNumber = currentNumber * 10 + (c - '0');
            }
            if((!isdigit(c) &&!isspace(c)) || (i == s.size() - 1)) {
                switch(operand) {
                case '+': 
                        result += lastNumber;
                        lastNumber = currentNumber;
                        break;
                case '-': 
                        result += lastNumber;
                        lastNumber = -currentNumber;
                        break;
                case '*': 
                    lastNumber = lastNumber * currentNumber;
                    break;
                case '/':
                    lastNumber = lastNumber / currentNumber;
                    break;
            }
            currentNumber = 0;
            operand = c;
            }
            
        }
        result += lastNumber;
        return result;
    }
};
/*
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
 

Constraints:

1 <= s.length <= 3 * 105
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 231 - 1].
The answer is guaranteed to fit in a 32-bit integer.
*/
