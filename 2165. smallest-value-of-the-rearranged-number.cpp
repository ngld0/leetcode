class Solution {
public:
    long long smallestNumber(long long num) {
        if(num ==0) return 0;
        long long ans = 0;
        bool negative = num < 0 ? true: false;
        num = num <0 ? -num: num;
        vector<int> nn;
        while(num != 0){
            nn.push_back(num%10);
            num/=10;
        }
        sort(nn.begin(), nn.end());
        if(negative){
            int i = nn.size() -1;
            while(i >= 0){
                ans = ans *10 + nn[i];
                i--;
            }
            
        }else{
            int i =0, j = 0;
            while(nn[i]==0){
                i++;
            }
            ans = nn[i];
            while(j < nn.size()){
                cout<< ans <<endl;
                if(j == i){
                    j++;
                    continue;
                }
                ans = ans * 10 + nn[j];
                
                j++;
            }
        }
        return negative? -ans:ans;
    }
  
  // using std function
  /*
  long long smallestNumber(long long num) {
        string s = to_string(abs(num));
        if(num>=0) sort(s.begin(),s.end());
        else sort(s.begin(),s.end(),greater<char>());
        if(num>0){
            int i=s.find_first_not_of('0');
            swap(s[0],s[i]);
        }
        long long ans = stoll(s);
        if(num<0){
            ans=ans*(-1);
        }
        return ans;
    }
  */
};
/*
You are given an integer num. Rearrange the digits of num such that its value is minimized and it does not contain any leading zeros.

Return the rearranged number with minimal value.

Note that the sign of the number does not change after rearranging the digits.

 

Example 1:

Input: num = 310
Output: 103
Explanation: The possible arrangements for the digits of 310 are 013, 031, 103, 130, 301, 310. 
The arrangement with the smallest value that does not contain any leading zeros is 103.
Example 2:

Input: num = -7605
Output: -7650
Explanation: Some possible arrangements for the digits of -7605 are -7650, -6705, -5076, -0567.
The arrangement with the smallest value that does not contain any leading zeros is -7650.
 

Constraints:

-10^15 <= num <= 10^15
*/
