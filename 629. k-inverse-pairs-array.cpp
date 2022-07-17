class Solution {
public:
    int kInversePairs(int n, int k) {
        int modulo = 1e9 + 7;
        int mm[1010][1010] = {};
        mm[0][0] = 1 ;        
        for(int i = 1; i <= n; i++){
            long long s = 0;

            for(int j = 0; j <= k; j++){
                s += mm[i-1][j];
                if(j >= i){
                    s -= mm[i-1][j-i];
                }
                mm[i][j] = ((long long) mm[i][j] + s) % modulo;
            }
        }
        return mm[n][k];
    }
};
