class Solution {
public:
//     vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
//         unordered_map<int, int> map;
//         vector<int> ret;
//         unordered_map<int, int>::iterator it;
        
//         sort(nums1.begin(), nums1.end());
//         nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end());
        
//         sort(nums2.begin(), nums2.end());
//         nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());
        
//         sort(nums3.begin(), nums3.end());
//         nums3.erase(unique(nums3.begin(), nums3.end()), nums3.end());
        
//         for(auto num1 : nums1){
//             map[num1]+=1;
//             cout<<num1<<endl;
//         }
//         for(auto num2 : nums2){
//             map[num2]++;
//         }
//         for(auto num3 : nums3){
//             map[num3]++;
//         }
        
//         for (it =  map.begin(); it !=  map.end(); ++it) {
//             if(it->second <= 1) continue;
//             ret.push_back(it->first);
        
//         }
//         return ret;
//     }
  // depending on constraint
  vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        bool cnt[3][101] = {};
        vector<int> res;
        for (auto n : nums1)
            cnt[0][n] = true;
        for (auto n : nums2)
            cnt[1][n] = true;
        for (auto n : nums3)
            cnt[2][n] = true;
        for (int i = 1; i <= 100; ++i)
            if (cnt[0][i] + cnt[1][i] + cnt[2][i] > 1)
                res.push_back(i);
        return res;
    }
};
/*
Given three integer arrays nums1, nums2, and nums3, return a distinct array containing all the values that are present in at least two out of the three arrays. You may return the values in any order.
 

Example 1:

Input: nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
Output: [3,2]
Explanation: The values that are present in at least two arrays are:
- 3, in all three arrays.
- 2, in nums1 and nums2.
Example 2:

Input: nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
Output: [2,3,1]
Explanation: The values that are present in at least two arrays are:
- 2, in nums2 and nums3.
- 3, in nums1 and nums2.
- 1, in nums1 and nums3.
Example 3:

Input: nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
Output: []
Explanation: No value is present in at least two arrays.
 

Constraints:

1 <= nums1.length, nums2.length, nums3.length <= 100
1 <= nums1[i], nums2[j], nums3[k] <= 100
*/
