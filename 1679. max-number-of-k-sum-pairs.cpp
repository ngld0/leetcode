class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int count = 0, len = nums.size();
        for(int i = 0, j = len-1; i < j;){
            if(nums[i] + nums[j] == k) {
                count++;
                i++;
                j--;
            }else if(nums[i] + nums[j] > k) j--;
            else i++;
        }
        return count;
    }
};
