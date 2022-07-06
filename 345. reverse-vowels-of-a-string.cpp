class Solution {
public:
    string reverseVowels(string s) {
        //set<char> vv = {'a', 'e', 'i', 'o', 'u'};
        int n = s.length();
        int left = 0, right = n -1;
        while(left<=right){
            char sL = tolower(s[left]), sR =tolower(s[right]) ;
            if( isVowel(sL) && isVowel(sR))
                swap(s[left++],s[right--]);
            if(!isVowel(sL) )
                left++;
            if (!isVowel(sR))
                right--;
        }
        return s;
    }
    bool isVowel(char sL){
        if(sL == 'a'||sL == 'e'||sL == 'i'||sL == 'o'||sL == 'u') return true;
        return false;
    }
};
