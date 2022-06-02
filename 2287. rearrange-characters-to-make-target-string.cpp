class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int s1 = s.length(), s2 = target.length();
        vector<int> count_t(26), count_s(26);
        for(int i = 0; i < s2;i++){
            count_t[target[i] - 'a']++;
        }
        for(int i = 0; i < s1;i++){
            count_s[s[i]-'a']++;
        }
        int ret = INT_MAX;
       
        for(int i = 0; i < s2;i++){
            //cout<< count_s[target[i] -'a'] << "--- "<<count_t[target[i] -'a']<<endl;
            int div = count_s[target[i] -'a']/count_t[target[i] -'a'];
            ret = min(ret,div );
        }
        return ret;
        
    }
};
