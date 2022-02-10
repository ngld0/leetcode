class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        int ans = 0;
        unordered_map<int, int> map;
        map[0]++;
        int sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum += nums[i];
            if (map.count(sum - k))
                ans += map[sum-k];
            map[sum]++;
        }
        return ans;
    }
};

/*
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-10^7 <= k <= 10^7
*/
