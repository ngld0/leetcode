class Solution {
public:
  //sol 1.
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        vector<int> newNum;
        if (n == 1) return nums[0];
        for(int i = 0 ; i < n/2;i++){
            
            if(i %2 ==0) nums[i] = min(nums[2*i], nums[2*i + 1]);
            else nums[i] =max(nums[2*i], nums[2*i + 1]);
        }
        nums = vector<int>(nums.begin(), nums.begin()+n/2);
        return minMaxGame(nums);
    }
  /*
  // sol 2.
  int minMaxGame(vector<int>& a) {
      for(int n= size(a); n>1 ; n-=(n/2)){
          for(int i=0;i<n/2;i++) 
          a[i]= (i%2)==1? max(a[2 * i], a[2 * i + 1]) : min(a[2 * i], a[2 * i + 1]);   
      }
      return a[0];
  }
  */
};
