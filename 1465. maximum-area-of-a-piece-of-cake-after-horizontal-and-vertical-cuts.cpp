class Solution {
public:
    int maxdistance(vector<int> & cuts,int end){
        cuts.push_back(0);
        cuts.push_back(end);
        sort(cuts.begin(),cuts.end());
        int r=0;
        for(int i=1;i<cuts.size();i++){
            r=max(r,cuts[i]-cuts[i-1]);
        }
        return r;
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int maxheight=maxdistance(horizontalCuts,h);
        int maxwidth=maxdistance(verticalCuts,w);
        int res;
        int mod=1e9 + 7;
        res =((long long)maxheight*maxwidth%mod);
        return res;
    }
};
