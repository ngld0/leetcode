int myAtoi(char * s){
        int res = 0;
        while(*s ==' '){
            s++;
        }
        int sign = 1;

        if(*s=='-'||*s=='+'){
            sign =  (s[0]=='-')?-1:1;
            s++;
        }

        for(int i= 0;i<strlen(s);i++){
            
            
            if(!isdigit(s[i]))break;
            
            int v = s[i] - '0';
            if (res > INT_MAX/10) {
                return sign==1?INT_MAX:INT_MIN;
            } else if (res == INT_MAX/10) {
                if (sign == 1 && v >= 7) return INT_MAX;
                if (sign == -1 && v >= 8) return INT_MIN;
            }
            res = 10*res +v;
                
        }
        
        return res*sign;
}
