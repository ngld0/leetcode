class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int mx = nums[0], mn = nums[0];
        for(auto num : nums){
            mx = max(mx, num);
            mn = min(mn, num);
        }
        return max(0, mx- mn -2*k);
    }
};
