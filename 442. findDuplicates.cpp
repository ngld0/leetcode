class Solution {
public:
    //Time complexity 0(n), space complexity 0(1) 
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        //0(nlog(n))
        //sort(nums.begin(), nums.end());
        vector<int> res;
        if(n < 2) return {};
        for(int i = 0;i<n;i++){
            /***
            cause by nums[i] in range [1,n]
                                                            [4,3,2,7,8,2,3,1]
            
            i = 0 => temp = 3 => nums[3]=7>=0 => nums[3] = -nums[3] = -7 =>nums = [4,3,2,-7,8,2,3,1]
            
            i = 1 => temp = 2 => nums[2]=2>=0 => nums[2] = -nums[2] = -2 => nums = [4,3,-2,7,8,2,3,1]
            
            i = 2 => temp = (2 - 1) = 1 => nums[1]=3>=0 => nums[1]=-nums[1] = -3 => nums = [4,-3,-2,7,8,2,3,1]
            
            i = 3 => temp = 6  => nums[6] =3 >=0 => nums[6] = -nums[6] = -3 => nums =  [4,-3,-2,7,8,2,-3,1]
            
            i = 4 => temp = 7   => nums[7] =1 >= 0 => nums[7] = -nums[7]  = -1 => [4,-3,-2,7,8,2,3,-1]
            
            i = 5 => temp = 1  => nums[1] = -3 < 0 => res = [2]
            
            i = 6 => temp = 2  => nums[2] = -2 < 0 => res = [2,3]
            
            i = 7 => temp = 0 => nums[0] =4 > 0 => nums[0] = -nums[0] = 1 => [-4,-3,-2,7,8,2,3,-1]
            ***/
            int temp = abs(nums[i])-1;
                     
            if(nums[temp] < 0) 
                res.push_back(temp+1);
            else
                nums[temp] = -nums[temp];
        }        
        return res;
    }
};
