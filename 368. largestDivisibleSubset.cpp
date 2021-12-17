class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int i,j,len=nums.size(),m=0,mi;
        vector<int> T(len,0);
        vector<int> son(len,0);
        sort(nums.begin(),nums.end());
        for(i=0;i<len;i++){
            for(j=i;j>=0;j--){
                if(nums[i]%nums[j]==0&&T[j]+1>T[i]){
                    T[i]=T[j]+1;
                    son[i]=j;
                }
            }
            if(T[i]>m){
                m=T[i];
                mi=i;
            }
        }
        vector<int> re;
        for(i=0;i<m;i++){
            re.insert(re.begin(),nums[mi]);
            mi=son[mi];
        }
        return re;
    }
};
/*
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.
*/
