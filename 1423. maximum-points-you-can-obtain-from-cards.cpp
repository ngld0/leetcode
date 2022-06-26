class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size()-1;
        int mm = 0;
        for(int i = 0; i < k;i++){
            mm += cardPoints[i];    
        }
        int ss = mm;
        for(int i = k-1 ; i >= 0 ; i--){
             ss = ss - cardPoints[i] + cardPoints[n--];
             mm = max(mm, ss);    
        }
       
        return mm;
    }
};
