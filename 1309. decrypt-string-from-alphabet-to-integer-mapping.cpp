class Solution {
public:
    string freqAlphabets(string s) {
        int n = s.length();
        string res = "";
        char ss[26];
        int i = 0;
        for(char a = 'a'; a <= 'z'; a++){
            ss[i++] = a;
        }
        for(int i = n-1;i>= 0 ; i--){ // O(n)
            if(s[i] =='#'){
                string tt = "";
                int cnt = 2;
                while(cnt){
                    tt += s[i-cnt];
                    cnt--;
                }

                int ch = stoi(tt) ;
                res = ss[ch-1] + res;
                i = i - 2;
            } else{
                int ch = s[i]-'0';
                res  = ss[ch-1] + res;                
            }

            
        }
        return res;
        
    }
};
