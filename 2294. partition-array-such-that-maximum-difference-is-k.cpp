class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int pre_idx = 0, cnt = 1;
        for(int i = 0 ; i < nums.size();i++){
            
            if(nums[i]- nums[pre_idx] <= k) continue;
            cnt++;
            pre_idx = i;
        }
        return cnt;
    }
};
