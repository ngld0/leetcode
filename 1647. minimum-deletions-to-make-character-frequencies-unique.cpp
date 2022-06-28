class Solution {
public:
    int minDeletions(string s) {
        int a[26]={0};
        for(char c : s){
            a[c-'a']++;
        }
        sort(a, a + sizeof(a)/sizeof(a[0]),greater<>()); // can use sort(a, a + 25));
        int res = 0;
        for(int i = 0 ; i < 26 && a[i] != 0 ;i++){
            int k = 0;
            for(int j = i+1; j < 26;j++){
                if( a[i]==a[j]){
                    cout<<a[j]<<endl;
                    k++;

                    if(a[j] - k <= 0){
                        k = a[j];
                        a[j] = 0; 
                    }
                    else 
                        a[j]-=k;
                    res+=k;
                } 
            }
        }
        return res;
        
    }
};
