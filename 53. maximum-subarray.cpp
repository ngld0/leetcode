class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, n = nums.size();
        //sol-1 O(n^3)
        /*
        for(int i = 0 ; i < n ; i++){
            for(int j = i;j< n;j++){
                int sum = 0;
                for(int k = i;k<= j;k++ ){
                    sum += nums[k];
                }
                ans = max(ans, sum);
            }
        }
        */
        //sol-2 O(n^2)
        /*
        for(int i = 0;i<n;i++){
            int sum = 0;
            for(int j = i;j<n;j++){
                sum += nums[j];
                ans = max(sum, ans);
            }
            
        }
        */
        // sol-3 O(n)
        /*
        int sum = 0;
        for(int i = 0; i < n;i++){
            sum += nums[i];
            //sum = max(nums[i],sum +nums[i]);
            ans = max(ans, sum);
            if(sum <0) sum = 0;
        }
        */
        // sol-4 O(n) Dynaic programming
        
        int sum = 0;
        for(int i = 0; i < n;i++){
            sum += nums[i];
            //sum = max(nums[i],sum +nums[i]);
            ans = max(ans, sum);
            if(sum <0) sum = 0;
        }        
        //Sol-5 O(n) divide and conquer
        /*
        willing to update ASAP
        */
        
        
        return ans;
    }
};

/*
//Older version of my code
class Solution {
public:
    //0(n)
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), res = INT_MIN;
        int sum = 0;
        if(n ==1) return nums[0];
        if(n == 0 )return 0;
        for (int i = 0 ; i < n ; i++){
            sum = max(sum+nums[i], nums[i]);
            res = max(sum, res);
        }
        
        return res;
    }
    //Device and Conquer
};
*/


/***
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
 

Constraints:

1 <= nums.length <= 3 * 104
-105 <= nums[i] <= 105
 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

***/
