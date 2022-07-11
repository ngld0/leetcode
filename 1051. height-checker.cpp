class Solution {
public:
    // Time O(nlogn); Space O(n)
    int heightChecker(vector<int>& heights) {
        vector<int> expected(heights.begin(), heights.end()); //cause of space O(n);
        
        sort(expected.begin(),expected.end()); //cause of Time O(nlogn)
        
        int cnt = 0;
        for (int i = 0;i < heights.size();i++){ //cause of time O(n)
            if(heights[i] != expected[i]) //checking the expected height and the current order
                cnt++;
        }
        return cnt;
    }
};
