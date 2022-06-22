class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*
        //using sort  O (nlogn)
        sort(nums.begin(), nums.end());

        return nums[nums.size()-k];
        */
        //without sort; O (n)
        // So the default sorting of priority_queue is descending, 
        // to reverse it, using priority_queue<int, vector<int>, greater<int>> que;
        priority_queue<int> que(nums.begin(), nums.end());
        int ret = 0;
        while(k>0){
            ret = que.top();
            que.pop();
            k--;
        }
        return ret;
    }
};
