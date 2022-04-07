class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        vector<int> ret;
        if(stones.size()==1) return stones[0];
        
        if(stones.size()==0) return 0;
        
        sort(stones.begin(), stones.end(), greater <>());
        if(stones[0]==stones[1]) ret.insert(ret.begin(), stones.begin()+2, stones.end());
        else {
            ret.push_back(stones[0]-stones[1]);
            ret.insert(ret.begin()+1, stones.begin()+2, stones.end());
        } 
        //stones = ret;
        return lastStoneWeight(ret);
    }
};
