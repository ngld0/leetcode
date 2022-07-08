class Solution {
public:
    //Time O(nlogn + n) = O(nlogn) for sorting algorithm;
    
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int countG = 0, countS = 0;
        while(countG < g.size() && countS < s.size()){
            if(s[countS] >= g[countG]){
                countG++;
                countS++;
            }
            else countS++;
        }
        return countG;
    }
};
