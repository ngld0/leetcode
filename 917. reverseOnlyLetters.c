char * reverseOnlyLetters(char * s){
        char* res = s;    
        int i =0;
        int j = strlen(s) -1;
        while(i<j){
            if(isalpha(s[i]) && !isalpha(s[j])){
                goto jd;
            } 
            if(isalpha(s[j]) && !isalpha(s[i])){
                i++;
                continue;
            }
            if(!isalpha(s[i]) && !isalpha(s[j])){
                goto in;
            }
            s[i] ^= s[j];
            s[j] ^= s[i];
            s[i] ^=s[j];
            in: 
                i++;
            jd:
                j--;
        }                                                           
       return res;
}
