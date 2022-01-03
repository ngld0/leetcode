class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        if(n == 1) return 1;
        
        vector<int> mp(n+1,0);
        
        for(auto &v:trust){
            mp[v[1]]++;
            mp[v[0]]--;
        }
        
        for(int i = 1; i <= n; i++){
            if(mp[i] == n-1) return i;
        }
        
        return -1;
    }
};
