class Solution {
public:
    // Sol 1.
//     int countMaxOrSubsets(vector<int>& nums) {
//         int bitwise_or_max = 0;
//         for(int num :nums){
//             bitwise_or_max |= num;
//         }
        
//         int ans = 0;
//         dfs(nums,0,0,bitwise_or_max, ans);
         
//         return ans;
//     }
//     void dfs(vector<int> nums,int pos,int p, int bitwise_or_max, int& ret){
        
//         if(p == bitwise_or_max) ret++;
        
//         for(int i = pos; i<nums.size(); i++){
            
//             dfs(nums, i+1, (p|nums[i]),bitwise_or_max, ret);
            
//         }
//     }
        
    int bitwise_or_max=0;
    int solve(vector<int>&nums, int i, int ret)
    {
        if(i==nums.size())
            return ret == bitwise_or_max ? 1 : 0;
        
        if(ret == bitwise_or_max) 
             return 1<<(nums.size()-i);
        
        return solve(nums,i+1,ret)+ solve(nums,i+1, ret|nums[i]);
            
            
    }
    int countMaxOrSubsets(vector<int>& nums) {
        for(int num: nums){
            bitwise_or_max = bitwise_or_max | num;
        }
        return solve(nums, 0, 0);
            
    }
};
/*
Given an integer array nums, find the maximum possible bitwise OR of a subset of nums and return the number of different non-empty subsets with the maximum bitwise OR.

An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b. Two subsets are considered different if the indices of the elements chosen are different.

The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1] (0-indexed).

 

Example 1:

Input: nums = [3,1]
Output: 2
Explanation: The maximum possible bitwise OR of a subset is 3. There are 2 subsets with a bitwise OR of 3:
- [3]
- [3,1]
Example 2:

Input: nums = [2,2,2]
Output: 7
Explanation: All non-empty subsets of [2,2,2] have a bitwise OR of 2. There are 23 - 1 = 7 total subsets.
Example 3:

Input: nums = [3,2,1,5]
Output: 6
Explanation: The maximum possible bitwise OR of a subset is 7. There are 6 subsets with a bitwise OR of 7:
- [3,5]
- [3,1,5]
- [3,2,5]
- [3,2,1,5]
- [2,5]
- [2,1,5]
 

Constraints:

1 <= nums.length <= 16
1 <= nums[i] <= 10^5
*/
