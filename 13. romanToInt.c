int romanToInt(char * s){
    int ans=0;
    for(int i=0; i<strlen(s); i++){
        if(s[i]=='I' && s[i+1]=='V'){
            i++;
            ans += 4;
        }
        else if(s[i]=='I' && s[i+1]=='X'){
            i++;
            ans += 9;
        }
        else if(s[i]=='X' && s[i+1]=='L'){
            i++;
            ans += 40;
        }
        else if(s[i]=='X' && s[i+1]=='C'){
            i++;
            ans += 90;
        }
        else if(s[i]=='C' && s[i+1]=='D'){
            i++;
            ans += 400;
        }
        else if(s[i]=='C' && s[i+1]=='M'){
            i++;
            ans += 900;
        }
        else if(s[i]=='I'){
            ans += 1;
        }
        else if(s[i]=='V'){
            ans += 5;
        }
        else if(s[i]=='X'){
            ans += 10;
        }
        else if(s[i]=='L'){
            ans += 50;
        }
        else if(s[i]=='C'){
            ans += 100;
        }
        else if(s[i]=='D'){
            ans += 500;
        }
        else if(s[i]=='M'){
            ans += 1000;
        }
    }
        return ans;
    
}
