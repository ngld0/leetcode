class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // slicing window; but time limited when cout<< "a message"; removing the cout<< then runtime is ok! 
        // slicing window using hashmap, O(n); space O(n);
        int score = 0, ans = -1;
        int r = nums.size(), l = 0;
        unordered_map<int, int> mm;
        for(int i = 0; i < r ; i++){
            score += nums[i];
            cout<<"hehe"<<endl;
            while(mm[nums[i]]>0){
                score -= nums[l];
                mm[nums[l++]]--;       
            }
            mm[nums[i]]++;
            ans  = max(score, ans);
            
        }
        return ans;
        
    }
};
