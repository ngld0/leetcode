class Solution {
public:
     // O(n) time;
    /*
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

    */
    // O(nlog(n)) time;
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int n =  nums.size();
        int cnt = 1, res = 0;
        
        for(int i = 1 ; i < n;i++){
            //cout<< nums[i] <<endl;
            if(nums[i] == nums[i-1]) continue;
            if(nums[i] == nums[i-1]+1) {
                cnt++;
                cout<< nums[i]<<endl;
            }
                
            else {
                res = max(cnt, res);
                cnt = 1;
            }
        }
        return max(cnt, res);
    }
};
