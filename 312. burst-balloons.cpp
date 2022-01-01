//sol 1.
class Solution {
public:
    //ref https://leetcode.com/problems/burst-balloons/discuss/76230/C%2B%2B-dp-detailed-explanation
    int maxCoins(vector<int>& nums) {
        // add the first and the last a element, the size of nums increase 2 element.
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(),0));
        for(int i = 0;i<= nums.size()-2;i++){
            int j = nums.size()-2 -i +1;
            for(int left = 1;left <=j ;left++){
                
                int right = left + i -1;
                for(int k = left; k <= right;k++){
                    dp[left][right] = max(dp[left][right], nums[left -1] *nums[k]* nums[right +1] + dp[left][k-1] + dp[k+1][right]);
                    //cout<< dp[left][right] <<endl;
                }
            }
        }
        return dp[1][nums.size()-2];
        
    }
};
//sol 2
class Solution {
public:
    
    int dp[502][502] = {};
    
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        nums.insert(nums.begin(), 1); nums.push_back(1);
        return rec(nums, 0, nums.size() - 1);
    }
    
    int rec(vector<int>& nums, int i, int j) {
        
        if(dp[i][j]) return dp[i][j];
        if(i == j) return nums[i];
        int ret = 0;
        
        for(int k = i + 1 ; k < j ; k++) {
            
            int t = rec(nums, i, k) + rec(nums, k, j) + nums[i] * nums[k] * nums[j];
            ret = max(ret, t);
        }

        return dp[i][j] = ret;
    }
    
};
