class Solution {
public:

    /*
    //Time O(n); Space O(n);
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> mm; //cause of space O(n);
        for(auto num:nums){ //cause of Time O(n)
            if(mm[num] != 0) return num;
            mm[num]++;
        }
        return 0;
    }    
    */
    // optimized; Using two pointers
    //Time O(n); space O(1)
    int repeatedNTimes(vector<int>& nums) {
        int one = nums[0], two = nums[1], three = nums[2]; // because of condition 2 <= n <= 5000 and nums.length == 2 * n
        if(one == two || one == three) {
            return one;
        }
        if(two == three) 
            return  two;
        for(int i = 3;i< nums.size();i++){ //cause of time O(n)
            //cout<< one<<two<<nums[i] <<endl;
            if(nums[i] == one || nums[i] == two || nums[i] == three) 
                return nums[i];
            one = nums[i-2];
            two = nums[i-1];
            three = nums[i];
        }
        return 0;
    }
};
