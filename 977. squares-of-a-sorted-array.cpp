class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size(), right = n-1, left = 0;
        
        vector<int> res(n); // cause of space O(n)
        
        int cur = n-1;   
        //cause of time space O(n)
        while(left <= right)
        {
            if(abs(nums[left]) < abs(nums[right])) { // the right most is greater
                res[cur--] = nums[right] * nums[right]; // square of current nums[i]
                right--;
            } else{ // incase left most is greater
                res[cur--] = nums[left] * nums[left]; 
                left++;
            }
        }
        
        return res;
    }
};
