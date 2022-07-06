class Solution {
public:
    

    /*
    string greatestLetter(string s) {
        int n = s.length()-1;
        int up = 0, low = 0;
        string ans = "";
        for(int i = 0 ; i <= n ; i ++ ){
            if(isupper(s[i])) up++;
            else
                low++;
        }
        sort(s.begin(),s.end(), greater<>());
         cout<<s<<endl;
        for(int i  = 0;i < low;i++){
            
            for(int j = 0; j< up;j++){
                if(s[i]-32 == s[j+low]) {
                    ans += s[j+low];
                    return ans ;
                }

            }
        }
        
       
        return ans;
    }
    */
    //
    string greatestLetter(string s) {

        std::vector<int> freq(128, 0);
        for (const char& c : s)
        {
            freq[c]++;
        }
        
        for (char c = 'Z'; c >= 'A'; c--)
        {
            if (freq[c] && freq[(c | 32)])
                return std::string(1, c);
        }
        
        return "";
    }

};
