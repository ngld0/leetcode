class Solution {
public:
    vector<int> grayCode(int n) {
        int cnt = pow(2,n);
        vector<int> ret(cnt);
        for(int i = 0 ; i < cnt;i++){
            
            ret[i] = i^(i>>1);
        }
        return ret;
    }
};
