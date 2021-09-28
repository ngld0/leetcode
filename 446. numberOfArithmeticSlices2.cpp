class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
       int res = 0, n = nums.size();
        
        // vector is used here to handle indices of duplicate elements
        unordered_map<int, vector<int>> a_idx;
        
        int dp[n][n];
        fill_n(&dp[0][0], n*n, 0);
        
        for (auto i = 0; i < n; ++i)
            a_idx[nums[i]].push_back(i);
        
        for (auto i = 0; i < n; ++i)
            for (int j = 0; j < i; j++) 
            {
                auto prev = 2l * nums[j] - nums[i];
                if (prev < INT_MIN || prev > INT_MAX)
                    continue;
                
                auto it = a_idx.find(prev);
                
                if (it != end(a_idx)) 
                    for (auto k : it->second) 
                    {
                        if (k >= j)
                            break;
                        
                        dp[i][j] += dp[j][k] + 1;
                    }
                
                res += dp[i][j];
            }
        
        return res;
    }
};

// class Solution {
// public:
//     int numberOfArithmeticSlices(vector<int>& nums) {
//         int res = 0, n = nums.size();
//         vector<unordered_map<int, int>> dp(n);
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < i; ++j) {
//                 long delta = (long)nums[i] - nums[j];
//                 if (delta > INT_MAX || delta < INT_MIN) continue;
//                 int diff = (int)delta;
//                 ++dp[i][diff];
//                 if (dp[j].count(diff)) {
//                     res += dp[j][diff];
//                     dp[i][diff] += dp[j][diff];
//                 }
//             }
//         }
//         return res;
//     }
// };
/***

ref: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/discuss/849944/C%2B%2B-with-picture%3A-base-%2B-optimizations

Intuition
My "rule of thumb" is that we should search for O(n) solution if we are dealing with consecutive sequences, and O(n ^ 2) if we are dealing with subsequences. Think about LCS algorithm as an example.

O(n ^ 2) solution for this problem is quite obvious. We memoise differences between the current element, and all elements before it. Then, when we see some difference again, we can tell how many elements form an arithmetic sequence with that difference.

image

Base Solution
This solution is accepted, however, make sure you check that the difference exists for a given element first. If you just do something like m[i][A[i] - A[j]] += m[j][A[i] - A[j]] + 1, it will add to the memory and runtime.

int numberOfArithmeticSlices(vector<int>& A, int res = 0) {
    unordered_map<long, int> m[max(1, (int)A.size())];
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < i; ++j) {
            auto it = m[j].find((long)A[i] - A[j]);
            int cnt = it == end(m[j]) ? 0 : it->second;
            m[i][(long)A[i] - A[j]] += cnt + 1;
            res += cnt;
        }
    return res;
}
Complexity Analysis

Time: O(n ^ 2)
Memory: O(n ^ 2)
Optimization 1
This solution has the same time complexity as above, but it runs 5 times faster in OJ due to pruning: we check if the next element in the arithmetic sequence - a[j] + d - exists before adding d to the hash map.

int numberOfArithmeticSlices(vector<int>& A, int res = 0) {
    unordered_map<int, int> m[max(1, (int)A.size())];
    unordered_set<int> s(begin(A), end(A));
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < i; ++j) {
            long d = (long)A[i] - A[j];
            if (d < INT_MIN || d > INT_MAX)
                continue;
            auto it = m[j].find(d);
            int cnt = it == end(m[j]) ? 0 : it->second;
            if (s.count((long)A[i] + d))
                m[i][d] += cnt + 1;
            res += cnt;
        }
    return res;
}
Optimization 2
This solution also has the same time complexity as above; it's inspired by the first optimization and runs even faster. Here, we first collect indices for each element in A.

Our dp[i][j] now track the number of the arithmetic sequence ending at i, with the difference a[i] - a[j]. Because of that, we can use an array instead of hash set, and this is why this solution is faster.

For each pair i and j, we check if the previous prev value exists. If so, we add it to the sequence. Note that more than one element with value prev can exist, so we are adding all with the index k < j.

int numberOfArithmeticSlices(vector<int>& A, int res = 0) {
    unordered_map<int, vector<int>> a_idx;
    vector<vector<int>> dp(A.size(), vector<int>(A.size()));
    for (auto i = 0; i < A.size(); ++i)
        a_idx[A[i]].push_back(i);
    for (auto i = 0; i < A.size(); ++i)
        for (int j = 0; j < i; j++) {
            auto prev = 2l * A[j] - A[i];
            if (prev < INT_MIN || prev > INT_MAX)
                continue;
            auto it = a_idx.find(prev);
            if (it != end(a_idx)) {
                for (auto k : it->second) {
                    if (k >= j)
                        break;
                    dp[i][j] += dp[j][k] + 1;
                }
            }
            res += dp[i][j];
        }
    return res;
}


***/


/***
Given an integer array nums, return the number of all the arithmetic subsequences of nums.

A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
For example, [1, 1, 2, 5, 7] is not an arithmetic sequence.
A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.

For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
The test cases are generated so that the answer fits in 32-bit integer.

 

Example 1:

Input: nums = [2,4,6,8,10]
Output: 7
Explanation: All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]
Example 2:

Input: nums = [7,7,7,7,7]
Output: 16
Explanation: Any subsequence of this array is arithmetic.
 

Constraints:

1  <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
***/
