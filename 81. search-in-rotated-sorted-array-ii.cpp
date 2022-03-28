class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //without sort
        int left = 0, right = nums.size() -1;
        while(left <= right){
            int mid = left + (right  -left)/2;
            if(nums[mid] == target)  return true;
            
            if(nums[mid] > nums[right]){
                if (target < nums[mid] && target >= nums[left])
                    right = mid - 1;
                else
                    left = mid +1;
          
            }
            else if(nums[mid] < nums[right]){
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else { 
                right--;
            } 
            
        }
        return false;
        
        //using sort vector function
        /*
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() -1;
        while(left <= right){
            
            int mid = left + (right - left)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid] < target) left = mid +1;
            else right = mid - 1;
        }
        return false;
        
        */
    }
};
