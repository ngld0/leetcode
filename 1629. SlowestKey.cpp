static const auto speedup = [](){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    return NULL;
}();
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char res = keysPressed[0];
        int max = releaseTimes[0];
        for(int i=0; i<releaseTimes.size()-1; ++i){
            int tmp = releaseTimes[i+1]-releaseTimes[i];
            if(tmp>max)
            {
                max = tmp;
                res = keysPressed[i+1];
            }
             else if(tmp==max && keysPressed[i+1]>res)
            {
                res = keysPressed[i+1];
            }
        }
        return res;
    }
};
