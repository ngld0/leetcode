class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        
        vector<pair<int,int>> v;
        
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        
        for(auto val: m){
            v.push_back({val.second,val.first});
        }
        sort(v.begin(),v.end());
        
        vector<int> ret;
        
        for(int i=v.size()-k;i<v.size();i++){
            ret.push_back(v[i].second);
        }
        return ret;
    }
};
