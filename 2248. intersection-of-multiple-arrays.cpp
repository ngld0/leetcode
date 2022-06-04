class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        
        vector<int> cnt(1001);
        for(int i = 0 ; i < n; i++){
            int m = nums[i].size();
            for(int j = 0 ; j < m; j++){
                cnt[nums[i][j]]++;
            }   
        }
        
        vector<int> count;
        
        for(int i = 0 ; i < cnt.size();i++){
            if(cnt[i] == n) count.push_back(i);
        }
        return count;
        
    }
};
