class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> appear;
        for (auto n : nums)
            appear[n]++;
        
        int maxi = 0;
        for (auto [num, ap] : appear) {
            if (appear.find(num+1) != appear.end())
                maxi = max(maxi, ap + appear[num+1]);
        }
        return maxi;
        
        
    }
};
