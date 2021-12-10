class Solution {
public:
    int numTilings(int n) {
        if (n < 3) return n;
        int modulo = 1e9 + 7;
        vector<long> domino(n+1, 0), tromino(n+1, 0);
        domino[0] = 0,domino[1] = 1, domino[2] = 2;
        tromino[0] = 0, tromino[1] = 1, tromino[2] = 2;
        
        for (int i = 3; i <= n; i++) {
            domino[i] = (domino[i-1] + domino[i-2] + 2*tromino[i-2]) % modulo;
            tromino[i] = (tromino[i-1] +domino[i-1]) % modulo;
        }
        return domino[n];
        
    }
};
/*
You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.


Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

 

Example 1:


Input: n = 3
Output: 5
Explanation: The five different ways are show above.
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 1000
*/
