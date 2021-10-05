class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n < 4) return {};
        for(int i = 0 ; i < n-3;i++){
            for(int j = i+1;j <n-2;j++){
                
                int left = j+1, right = n-1;
                while(left<right){
                    
                    long end = (long)target - nums[i]-nums[j] - nums[left];
                    if(nums[right] > end) right--;
                    else if(nums[right] < end) left++;
                    else {
                        res.insert({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                    }
                }
            }  
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};

//can improve my support kSum like this
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return NSum(nums, 0, nums.size() - 1, 4, target);
    }
private:
    vector<vector<int>> NSum(vector<int>& nums, int left, int right, int N, int target){
        vector<vector<int>> answer;
        // early stop
        if (right - left + 1 < N || N < 2 || target < (long) nums[left] * N || target > nums[right] * N)
            return answer;
        if (N == 2)
            return TwoSum(nums, left, right, target);
        else{
            for (int i = left; i < right; i++){
                if (i > left && nums[i] == nums[i - 1])
                    continue;
                vector<vector<int>> results = NSum(nums, i + 1, right, N-1, target - nums[i]);
                for (auto& result : results){
                    result.push_back(nums[i]);
                    answer.push_back(result);
                }
                
            }
        }
        return answer;
    }
        vector<vector<int>> TwoSum(vector<int>& nums, int left, int right,
                               int target) {
        vector<vector<int>> result;
        while (left < right) {
            if (nums[left] + nums[right] == target) {
                result.push_back({nums[left], nums[right]});
                while (left + 1 < right && nums[left] == nums[left + 1]) left++;
                while (right - 1 > left && nums[right] == nums[right - 1])
                    right--;
                left++;
                right--;
            } else if (nums[left] + nums[right] < target)
                left++;
            else
                right--;
        }
        return result;
    }
};
/***
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

***/
