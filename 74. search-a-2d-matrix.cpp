class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size()-1;
        for(int i = 0 ; i < matrix.size();i++){
            
            if(matrix[i][0] <= target && matrix[i][m] >= target ){
                return binarysearch(matrix[i], target);
            }
        }
        return false;
    }
    bool binarysearch(vector<int> arr, int target){
        
        int left = 0, right = arr.size() -1;
        while(left <= right){
            int mid = left + (right -left)/2;
            if(arr[mid]==target) return true;
            else if(arr[mid]> target) right = mid - 1;
            else left = mid+1;
            
        }
        return false;
    }
};
