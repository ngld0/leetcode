class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         int n = nums.size();
        
        vector<vector<int>>ans;
        vector<int>temp;
        
        recursion(temp,n-1,nums,ans);
        
        return ans;
    }
    
    void recursion(
        vector<int>temp,int n,
        vector<int>nums,
        vector<vector<int>>&ans){
        
        if(n < 0){ 
            ans.push_back(temp);
            return;
        }
        
        // not including n-1th element 
        recursion(temp,n-1,nums,ans);
        // including n-1th element
        temp.push_back(nums[n]);
        recursion(temp,n-1,nums,ans);
    }
    
};
/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/
