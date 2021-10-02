class Solution {
public:
    //min(target - (num[i]+nums[j]+nums[k]))

    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        int closed = nums[0] +nums[1]+nums[2];
        
        int check = abs(target - closed);
        
        for(int i = 0;i< n - 2;i++){
            
            int left = i+1; 
            
            int right = n-1;
            
            while(left < right){
                
                int sum = nums[i] + nums[left] + nums[right];
                
                if(check > abs(target - sum)){
                    
                    closed = sum;
                    
                    check = abs(target - sum);
                   
                } 
                if(sum<target ) left++;
                else right--;
            }
            
        }
        return closed;
    }
};
/***
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
 

Constraints:

3 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
-104 <= target <= 104
***/
