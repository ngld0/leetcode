class Solution {
public:
    // Time limited; slicing window
    /*
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n= nums.size();
        for(int i = 0; i < n;i++){
            int j = i+1 ;
            while(j < n && j <= k + i){
                if(nums[i] == nums[j]) return true;
                j++;
            }
        }
        return false;
    }
    */
    //using map;
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mm;
        int n= nums.size();
        for(int i = 0; i < n;i++){
            
            if(mm.find(nums[i])!= mm.end() && i - mm[nums[i]]<= k) return true;
            mm[nums[i]] = i;
        }
        return false;
    }

};
