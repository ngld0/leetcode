class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n  = nums.size();
        vector<int> cnt(501);
        for(int i =0 ; i < nums.size();i++){
            cnt[nums[i] ]++;
        }
        for(auto cc : cnt){
            if(cc %2 != 0 )return false;
        }
        return true; 
    }
};
