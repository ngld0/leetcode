class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        
        vector<int> ret;
        
        int mm[10] = {0};
        
        for(int i :digits){
            mm[i]++;
        }
        //bruteforce all even number from 100 to 999 ;
        
        for(int i=100;i<999;i+=2)
        {
            int d1=i/100, d2=i/10%10, d3=i%10;
            
            mm[d1]--;
            mm[d2]--;
            mm[d3]--;
            if(mm[d1] >= 0 & mm[d2]>=0 & mm[d3]>=0) 
                ret.push_back(i);
            mm[d1]++;
            mm[d2]++;
            mm[d3]++;                                 
        }
        
        return ret;
        
    }
};
