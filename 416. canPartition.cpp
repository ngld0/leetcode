class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(auto num:nums){
            sum += num;
        }
        if(sum%2) return false;
        
        sort(nums.begin(),nums.end());
        
        vector<int> dp(sum / 2 + 1, 0);
        
        for (int i = 1; i <= n; ++i)
        {
            for (int j = sum / 2; j >= 0; --j)
            {
                int x = nums[i - 1];
                dp[j] = max(dp[j], (j >= x) ? dp[j - x] + x : 0);
            }
        }
        return dp[sum / 2] == sum / 2;
    }
    
};
/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/
