class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int, int> mm;
        for(auto mag : magazine){
            mm[mag]++;
        }
        
        int n = ransomNote.length();
        for(auto ran: ransomNote){
            if(mm[ran]==0) return false;
            mm[ran]--;
        }
        return true;
    }
};
