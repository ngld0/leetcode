//0 ms
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int res = 0;
        
        if(nums.size()==0) return 0;
        
        int j=n-1, i=0;
        
        while(i<n ){
            if(nums[i]==val){
                while(j>i){
                    if(nums[j]!= val){
                        nums[i] = nums[j];
                        j--;
                        break;
                    }
                    j--;
                }
            }else{
                
                res++;
            }
            i++;
        }
        return res;
    }
};
//4ms
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=val)
            {
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
};
