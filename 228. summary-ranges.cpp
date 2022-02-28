class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret; 
        
        int n = nums.size();
        if(n == 0) return ret;
        int i = 0;
        while(i < n){
            int end = i;
            
            while(end + 1 < n && nums[end] == nums[end+1] -1){ 
                end++; 
            }
            if (end > i) ret.push_back(to_string(nums[i]) + "->" + to_string(nums[end]));
            
            else ret.push_back(to_string(nums[i]));
            
            i = end+1;
        }
        return ret;
        
    }
};
