class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
          // approach 2. using 2 vector to forward and backward;
        int len = nums.size();
        vector<int> v1(len,0), v2(len, 0);
        
        //set the first element of forward vector is the first element of nums
        v1[0] = nums[0];
        
        //set the last element of backward vector is the last element of nums
        v2[len-1] = nums[len - 1];
        
        //put to forward vector, if it greater than the previous then put it to the forward vector
        for(int i = 1; i < len;i++){
            if(v1[i-1] < nums[i])
                v1[i] = nums[i];
            else 
                v1[i] = v1[i-1];
        }
        
        // put to backward vector, if it is smaller than the current then put it to the backward vector;
        for(int i = len -2; i >= 0;i--){
            if(nums[i] < v2[i+1])
                v2[i] = nums[i];
            else
                v2[i] = v2[i+1]; 
        }
        // use this following code to display two vectors
        cout<<"Forward vector: ";
        for(int i = 0;i<len;i++){
            cout<< v1[i]<<", ";
        }
        cout<< "\nBackward vector: ";
        for(int i = 0;i<len;i++){
            cout<< v2[i]<<", ";
        }
        
        /*
        using two pointers (left and right)  to count the result
        
        Example 1. [2,6,4,8,10,9,15]
            Forward vector: 2, 6, 6, 8, 10, 10, 15, 
            Backward vector: 2, 4, 4, 8, 9, 9, 15, 
        Example 2. [1,2,3,4]
            Forward vector: 1, 2, 3, 4, 
            Backward vector: 1, 2, 3, 4,  
        */
        
        int left = 0,right = len -1;
        while(left < len && v1[left] == v2[left]){
            left++;
        }
        while(right >= 0 && v1[right]==v2[right]){
            right--;
        }        
        return left >= right ? 0:right-left + 1;
        
        
        /* 
        // approach 1. time complexity is O(nlogn), space O(n);
        int right = nums.size() -1;
        int left = 0;
        if(right <1) return 0;
        
        while(right > left){
            
            int max = *max_element(nums.begin() +left, nums.begin()+right+1);
            
            int min = *min_element(nums.begin() + left, nums.begin()+right+1);
            if(max == nums[right] || min == nums[left]){
                if(max == nums[right]) 
                    right--;
                if(min == nums[left])
                    left++;
                continue;
            }
            break;
        }
        return left==right?0:right - left + 1;
        */
        
      
    }
};
