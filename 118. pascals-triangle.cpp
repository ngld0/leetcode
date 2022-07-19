class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r(numRows); //caused of space O(n)

        for (int i = 0; i < numRows; i++) {
            r[i].resize(i + 1); // set the size for each row
            r[i][0] = 1; // set the first cell
            r[i][i] = 1; // set the last cell
  
            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j]; // calculate the current cell,
        }
        
        return r;
    }
};
