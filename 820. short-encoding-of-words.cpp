class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        //sol 1.
        int ans = 0;
        unordered_set<string> ss(words.begin(), words.end());

        cout<<"---------"<<endl;
        for(auto w:words){
            //cout<< "working on: "<<w<<endl;
            for(int i = 1; i < w.length();i++){
                //cout<< "removing: "<<w.substr(i)<<endl;
                string rm = w.substr(i);
                ss.erase(rm);
            }
            
        }
        for(auto s:ss){
            ans += s.length() +1;
        }
        return ans;
    }
};
