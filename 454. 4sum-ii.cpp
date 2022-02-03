class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // use temporary sum to sum each element of nums1 with all element of nums2. And then save all sum values to the following map.
        // The first is the sum value, and the second is the time this value represent.
        unordered_map<int, int>  sum_n1_n2;
        
        for(int n1 : nums1) {
            for(int n2 : nums2) {
                ++sum_n1_n2[n1+n2];
            }
        }
        
        int count = 0;
        
        for(int n3 : nums3) {
            for(int n4 : nums4) {
                auto it = sum_n1_n2.find(0 - n3 - n4);
                
                if(it != sum_n1_n2.end()) {
                    count += it->second;
                }
            }
        }
        return count;
    }
};

/*
int main()
{
    vector<int> nums1, nums2, nums3,nums4;
    
    nums1 = {1,2}, nums2 = {-2,-1}, nums3 = {-1,2}, nums4 = {0,2};
    
    return fourSumCount(nums1, nums2,nums3, nums4);

    //return 0;
}
Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 

Example 1:

Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
Output: 2
Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
Example 2:

Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
Output: 1
 

Constraints:

n == nums1.length
n == nums2.length
n == nums3.length
n == nums4.length
1 <= n <= 200
-2^28 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 2^28

*/
