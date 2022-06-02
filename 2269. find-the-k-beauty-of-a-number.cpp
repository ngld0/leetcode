class Solution {
public:
    int divisorSubstrings(int num, int k) {
        
        string snum = to_string(num);
        int n = snum.length(), count = 0;
        for(int i = 0 ; i<= n-k;i++){
            int subn = stoi( snum.substr(i, k) );
            if(subn != 0 && num %subn ==0) {
                count++;
            }           
        }
        return count;
    }
};
