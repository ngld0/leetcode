class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> record(nums.begin(), nums.end());
        int ans=0;
        for(int it: nums){
            if(record.find(it)==record.end())   
                continue;
            int prev = it-1, next = it+1;
            while(record.find(prev)!=record.end()) 
                prev--;
            while(record.find(next)!=record.end()) 
                next++;
            ans = max(ans, next-prev-1);                 
            record.erase(it);
        }
        return ans;
    }
};
