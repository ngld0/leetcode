class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>> res;
        helper(nums, res,0 );
        return res;
    }
    
    void helper(vector<int>& nums, vector<vector<int>> &res, int start){
        int n = nums.size();
        if(start >= n){
            res.push_back(nums);
            return;
        }
        for(int i = start; i<n;i++){
            swap(nums[start], nums[i]);
            
            helper(nums, res, start+1);
            //backtrack
            swap(nums[start], nums[i]);
            
        }        
    }
};
/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/
