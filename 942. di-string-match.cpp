class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        int dec = n, inc = 0;
        vector<int> res; //casued of space O(n)
        for(auto c : s){ //cause of time O(n)
            if(c == 'I'){ // incrase if char is 'I'
                res.push_back(inc++);
            }else { // decrease if char is 'D'
                res.push_back(dec--);
            }
        }
        if(s[n-1] == 'D') // checking the last character,
            res.push_back(res[n-1]-1);
        else 
            res.push_back(res[n-1]+1);
        return res;
    }
};
