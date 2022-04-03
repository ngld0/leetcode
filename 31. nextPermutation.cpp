//// https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
/*
1. Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
2. Find the largest index l > k such that nums[k] < nums[l].
3. Swap nums[k] and nums[l].
4. Reverse the sub-array nums[k + 1:].
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int n = nums.size(), i , j;
        
        for (i=n-2;i>=0;--i)
        {
            if(nums[i] < nums[i+1]) break;          // find 1st decreasing element 
        }
        
        if(i < 0)   reverse(nums.begin(),nums.end());
        else
        {
            for(j=n-1;j>=i;--j)
            {
                if(nums[j] > nums[i])   break;      // find 1st element greater than nums[i];
            }
            swap(nums[i],nums[j]);
            
            reverse(nums.begin()+i+1,nums.end());       // reverse all elements after index i
        }
    }
};
/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
Example 4:

Input: nums = [1]
Output: [1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100
*/
