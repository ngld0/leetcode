class Solution {
public:
    int largestInteger(int num) {
        string snum = to_string(num);
        int n = snum.size();
        vector<int> odd;
        vector<int> even;
        for(auto i: snum){
            if((i -'0')%2==0) even.push_back(i);
            else odd.push_back(i);
        }
        
        sort(even.begin(),even.end()); // 0(nlog(n))
        sort(odd.begin(),odd.end()); // 0(nlog(n))
        int a = even.size()-1;
        int b = odd.size()-1;
        
        for(int i = 0 ; i <n;i++){
            
            if((snum[i]-'0')%2 == 0) {
                snum[i] = even[a--];
            }else 
                snum[i] = odd[b--];
        }
        return stoi(snum);
    }
};
