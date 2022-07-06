class Solution {
public:
    // SOl 1. using sort O(nlogn)
    /*
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return false;
        sort(nums.begin(),nums.end());
        for(int i = 1; i < nums.size();i++){
            if(nums[i] == nums[i-1]) return true;
        }
        return false;
    }
    */

    // SOl 2. Time O(n); space O(n);
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return false;
        //sort(nums.begin(),nums.end());
        unordered_map<int,int> mm;
        for(int i = 0; i < nums.size();i++){
            mm[nums[i]]++;
            //cout<< mm[nums[i]]++<<endl;
            if(mm[nums[i]]==2) 
                return true;
        }
        return false;
    }
};
