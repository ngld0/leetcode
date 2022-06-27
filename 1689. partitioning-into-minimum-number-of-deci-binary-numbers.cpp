class Solution {
public:
    int minPartitions(string n) {
        int tmp = 0;
        for(char c : n){
            int cc = c - '0';
            if(cc == 9)
                return cc;
            if(cc > tmp) tmp = cc;
        }
        return tmp;
    }
};
