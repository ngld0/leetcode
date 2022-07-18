class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // mm to count the frequency of number; travel to not the number is traversal or not
        unordered_map<int,int> mm, travel;
        
        int maxcnt = INT_MIN;
        for(auto num: nums){
            mm[num]++;
            maxcnt = max(maxcnt, mm[num]);
        }
        int minlength = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++){
            if(mm[nums[i]] == maxcnt && travel[nums[i]] == 0){ // just count the length of nums have max frequency
                
                int start = i;
                int remaining = maxcnt - 1;
                int j = i+1;
                int last = start;
                while(j < nums.size() && remaining > 0){
                    if(nums[j] == nums[i]){
                        remaining--;
                        last = j;
                    }
                    j++;
                }
                minlength = min(last - start +1,minlength); // select the num length;
                travel[nums[i]] = 1; // if we travel nums[i] then set it to 1,
            }
        }
        
        return minlength;
    }
};
