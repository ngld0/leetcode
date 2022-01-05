class Solution {
public:
    bool isPallendrome(string &s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    void helper(int curr,string& s, vector<vector<string>> &ans,vector<string>& temp)
    {
        if(curr>=s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=curr;i<s.size();i++)
        {
            if(isPallendrome(s,curr,i))
            {
                temp.push_back(s.substr(curr,i-curr+1));
                helper(i+1,s,ans,temp);
                temp.pop_back();
            }
        }
        return;
    }
    
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> temp;
        helper(0,s,ans,temp);
        return ans;
    }
};
