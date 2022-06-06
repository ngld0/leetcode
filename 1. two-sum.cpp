class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashMap;
        int i=0;
        for (i=0;i<nums.size(); i++){
            
           if(hashMap.find(target-nums[i])!=hashMap.end()) 
               return {hashMap[target-nums[i]],i};
            hashMap[nums[i]]=i;
        }
        return {};
    }
};
