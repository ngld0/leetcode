class Solution {
public:
    //bruteforce
//     void moveZeroes(vector<int>& nums) {
//         int n = nums.size();
//         for(int i = 0;i < n;i++){
            
//             if(nums[i] != 0 ) continue;
//             for(int j = i +1; j<n;j++){
//                 if(nums[j]==0) continue;
//                 swap(nums[i], nums[j]);
//                 break;
//             }
//         }
//     }
     void moveZeroes(vector<int>& nums) {
         int n = nums.size();
         int j = 0;
         for(int i =0;i<n;i++){
             if(nums[i] != 0){
                 nums[j++] = nums[i];
             }
         }
         for(;j<n;j++){
             nums[j] = 0;
         }
         
     }
};
