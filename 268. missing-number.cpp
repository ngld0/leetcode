class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int mask =0, ans = nums.size();
        for (int i = 0; i < nums.size();i++){
            ans ^= nums[i];
            mask ^= i;
        }
        return mask^ans;
    }
};
