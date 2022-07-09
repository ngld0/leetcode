class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> sA;
        int mm[1001] = {0};
        for(int num1: nums1){
            mm[num1]++;
        }
        for(int num2:nums2){
            if(mm[num2] != 0){
                sA.insert(num2);
            }
        }
        return vector<int>(sA.begin(),sA.end());
        
        
    }
};
