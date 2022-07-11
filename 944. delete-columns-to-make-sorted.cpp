class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), cnt = 0;
        if(n<=1) 
            return 0;
        for(int i = 0 ; i < strs[0].length();i++){ // Time O(n^2); Space O(1)
            for(int j = 1; j < n; j++){
                int tt = (strs[j][i] - 'a') - (strs[j-1][i] - 'a');
                if(tt < 0) {
                    cnt++;
                    break;
                }
                
            }
            
        }
        return cnt;
    }
};
