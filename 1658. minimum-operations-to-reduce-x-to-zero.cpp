class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(auto num : nums) sum += num; //sum = accumulate(nums.begin(), nums.end(), 0);
        int l = 0, r = 0, res = INT_MAX, sz = nums.size();
        while (l <= r)
            if (sum >= x) {
                if (sum == x)
                    res = min(res, l + sz - r);
                if (r < sz)
                    sum -= nums[r++];
                else
                    break;
            }
            else
                sum += nums[l++];
        return res == INT_MAX ? -1 : res;
    }
    /*
    // sol 2. 
    int minOperations(vector<int>& nums, int x) {
        //slicing window
       int totalsum = 0;
        for(int i=0;i<nums.size();i++) 
            totalsum += nums[i];
        int sum = totalsum - x;
        
        if(sum < 0) 
            return -1;
        if(sum == 0) 
            return nums.size();
        int start = 0, add  = 0, len = -1;
        // max size of window => min of the operation!!
        for(int end = 0; end < nums.size(); end++)
            {
            if (add < sum)
                add += nums[end];
            while (add >= sum)
            {
                if (add == sum)
                    len = max(len, end - start + 1);
                add -= nums[start++];
            }
        }

        return len == -1 ? -1 : nums.size() - len;
    }
    */
};
