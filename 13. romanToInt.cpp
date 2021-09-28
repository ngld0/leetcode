class Solution {
public:
    int romanToInt(string s) {
         int count=0;
        unordered_map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L',50}, {'C',100}, {'D',500},{'M',1000}};
        for(int i= s.size()-1;i>=0;i--){
           auto itr=roman.find(s[i]);
               if(i==s.size()-1){
           count=count + itr->second ;
               }
           else{
               auto itr2=roman.find(s[i+1]);
               if(itr->second<itr2->second)
                   count=count-(itr->second);
               else
                  count=count +itr->second ; 
           }
       }
        return count;
    }
};
