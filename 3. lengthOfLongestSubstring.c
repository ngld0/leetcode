int lengthOfLongestSubstring(char * s){
    int res=0, pivot = -1;
    int map[128];
    
    for(int i=0;i<128;i++) map[i]=-1;
    
    for(int i = 0;i<strlen(s);i++){
        pivot=(pivot > map[s[i]]?pivot:map[s[i]]);
        map[s[i]] = i;    
        res = (res > (i- pivot))?res:(i- pivot);
    }
    return res;
}
