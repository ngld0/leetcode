class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        if(len < 3) return false;
        int min = INT_MIN;
        stack<int> st;
        //132 pattern means: nums[i] < num[j] and nums[i] < nums[k] and nums[k] < nums[j] for all i<j<k is the indices 
        for(int i = len -1;i>=0;i--){
            //check for i value
            if(nums[i]<min) return true;
            
            else {
                //check of j value
                while(!st.empty() && nums[i]>st.top()){
                    min = st.top();
                    st.pop();
                    
                }
            }
            st.push(nums[i]);     
        }
        return false;
    }
};
