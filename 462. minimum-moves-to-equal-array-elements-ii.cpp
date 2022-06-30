class Solution {
public:
    
    // minimized squared differences should use MEAN.
    // minimized absolute differences should use MEDIAN; The Median is the "middle" of a sorted list of numbers.
    int minMoves2(vector<int>& nums) {
        //searching the median value by sorting the array
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int median_index = n/2,res = 0;
        for(int i = 0 ; i < n;i++){
            //if(i == median_index) continue;
            res += abs(nums[i]- nums[median_index]);
        }
        return res;
    }
};
