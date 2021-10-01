class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0; i<=n-3;i++){          
            if(i>0 and nums[i]==nums[i-1]) continue;     	
            int j=i+1, k=n-1;            
            while(j<k){                     
                int s=nums[i]+nums[j]+nums[k];
                if(!s){               
                    res.push_back({nums[i],nums[j], nums[k]}); 
        
                    int val1=nums[j];
                    while(j<k and val1==nums[j]) j++;
                    int val2=nums[k];
                    while(j<k and val2==nums[k]) k--;  
                }
                
                else if(s>0)k--; 
                
                else j++;
            }
        }
        return res;
    }
};
/***
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105
***/
