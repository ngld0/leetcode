class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        /*
        // using queue, after init all value in queue are sorted!!!
        priority_queue<int> st(stones.begin(), stones.end());
        while(st.size() > 1){
            int y = st.top();
            st.pop();
            int x = st.top();
            st.pop();
            if(x!=y) st.push(y -x);
        }
        return st.top();
        */
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
