class Solution {
public:
    int minTimeToType(string word) {
        // typing time for each word;
        int n = word.size();
        //first pointer to a
        char point = 'a';
        for(auto w : word){
            // time to move from pointer to current word.
            n += min(abs(w-point), 26 - abs(w - point));
            point = w;
        }
        return n;
    }
};
