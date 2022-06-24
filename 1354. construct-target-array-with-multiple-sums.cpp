class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> qq(target.begin(),target.end());
        long long sum = 0, val;
        for (auto t : target){
            sum += t;
        }
        while(true){
            val = qq.top(); qq.pop();
            sum -= val;
            if(val==1||sum==1) return true;
            if(val<sum || sum ==0 || val%sum==0) return false;
            val %= sum;
            sum += val;
            qq.push(val);
        }
        
    }
};
