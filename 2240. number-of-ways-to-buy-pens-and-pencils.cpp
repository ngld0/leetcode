class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long cnt = 0;
        for(int i = 0 ;i*cost1  <= total;i++){
        
            cnt +=(total - i*cost1)/cost2 +1;
        }
        return cnt;
    }
};
