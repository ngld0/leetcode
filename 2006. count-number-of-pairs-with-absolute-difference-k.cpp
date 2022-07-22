class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        //step 1.
        int n = nums.size(),cnt = 0 ;
        
        //Step 2.
        //SOL 1. bruteforce
        /*
        //step 1.1 counting the number of pairs
        for(int i = 0;i<n;i++){
            for(int j =i+1;j<n;j++){
                if(abs(nums[j]-nums[i]) == k) cnt++;                
            }
        }        
        */
        //SOL2. optimizing to O(n)
        //   step 2.1. count the frequency of each num (1 <= nums[i] <= 100)
        int fre[101] = {0}; 
        for(auto num:nums){
            fre[num]++;
        }
        // step2.2 counting the number of pairs where |nums[i] - nums[j]| == k
        for(int i = 0;i < 101; i++){
            if(fre[i]==0 ) continue;
            int add = k + i;            
            if(add < 101 && fre[add] != 0){
                cnt += (fre[i] * fre[add]);
            }
        }
        return cnt;
    }
};
