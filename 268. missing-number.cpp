class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //math: 1 + 2+ ... + n = n(n+1)/2
        int n = nums.size();
        int sum = n * (n+1)/2;
        for(int i =0;i<n;i++){
            sum -= nums[i]; 
        }
        return sum;
        
        //bit manipulation
        /*
        int mask =0, ans = nums.size();
        for (int i = 0; i < nums.size();i++){
            ans ^= nums[i];
            mask ^= i;
        }
        return mask^ans;
        */
    }
};
