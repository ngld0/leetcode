class Solution {
public:
    int percentageLetter(string s, char letter) {
        unordered_map<int, int> mm ;
        int n = s.length();
        for(int i = 0; i < n;i++){
            mm[s[i]]++;
            
        }
        cout<< mm[letter]<< n <<endl;
        int ans = mm[letter] * 100 / n;
        return  ans;
        
    }
};
