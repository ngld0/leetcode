class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, int> m;
        
        int ret = 0, mod = 1e9 + 7;
        
        for (int i = 0; i < arr.size(); i++) {
            ret = (ret + m[target - arr[i]]) % mod;
            
            for (int j = 0; j < i; j++) {
                m[arr[i] + arr[j]]++;
            }
        }
        return ret;
    }
};
