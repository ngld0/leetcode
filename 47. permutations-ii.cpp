class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        
        permute(res, nums, 0);
        
        return res;
    }
    void permute(vector<vector<int>>& res, vector<int>& nums, int pos) {
        if (pos == nums.size()) {
            
            res.push_back(nums);
            
        } else {
            
            for (int i = pos; i < nums.size(); ++i) {
                
                if (i > pos && nums[i] == nums[pos]) 
                    continue;
                
                swap(nums[pos], nums[i]);
                
                permute(res, nums, pos + 1);

            }
            for (int i = nums.size() - 1; i > pos; --i) {
                
                swap(nums[pos], nums[i]);
                
            }
        }
    }
};
