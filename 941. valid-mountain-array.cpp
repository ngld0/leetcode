class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        // Sol 1.
//         if(arr.size() <3) return false;
//         int m = arr[0], idx_max = 0;
//         for(int i = 0; i < arr.size();i++){
            
//             if(m < arr[i]){
//                 m = arr[i];
//                 idx_max = i;
//             }
//         }
//         if(idx_max == arr.size() -1 ||idx_max == 0 ) return false;
//         for(int i =1;i<= idx_max;i++){
//             if(arr[i-1] >= arr[i]) return false;
//         }
//         for(int i = idx_max + 1;i <arr.size();i++ ){
            
//             if(arr[i-1] <= arr[i]) return false;
//         }
//         return true;
        //Sol 2.
        if(arr.size() <3) return false;
        int i = 1;
        while(i < arr.size() && arr[i-1] < arr[i]) i++;
        if(i == arr.size() || i == 1) return false;
        while(i < arr.size() && arr[i-1] > arr[i]) i++;
        if(i == arr.size()) return true;
        return false;
    }
};
/*
Given an array of integers arr, return true if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

 

Example 1:

Input: arr = [2,1]
Output: false
Example 2:

Input: arr = [3,5,5]
Output: false
Example 3:

Input: arr = [0,3,2,1]
Output: true
 

Constraints:

1 <= arr.length <= 10^4
0 <= arr[i] <= 10^4
*/
