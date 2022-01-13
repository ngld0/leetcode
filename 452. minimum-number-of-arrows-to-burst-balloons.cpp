class Solution {
public:
    /* Sol 1. Timeout :((( 
//     static bool cmp(vector<int> a, vector<int> b){
//         return (a[1] < b[1]);
//     }
//     int findMinArrowShots(vector<vector<int>>& points) {
//         if(points.size() <= 1) return points.size();
       
//         sort(points.begin(), points.end(), cmp);
        
//         int ans = 0, temp = points[0][1];
//         for(int i = 1; i<points.size(); i++){
//             ans += points[i][0] > temp;
//             temp = points[i][0] > temp ?  points[i][1] : temp;
            
//         }
//         return ans + 1;
//     }*/ 
    
    // Sol 2. faster than sol 3.
    int findMinArrowShots(vector<vector<int>>& points) {
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);  
       sort(points.begin(), points.end());
       int ans = 0, n = points.size();
       int i = n - 1;
       while (i >= 0) {
           ans++;
           int an = points[i][0];
           while (i >= 1 && points[i - 1][1] >= an) i--;
           i--;
       }
       return ans;
    }
    
    /*
    // Sol 3. Ref from leetcode
    int findMinArrowShots(vector<vector<int>>& p) {
        // added the two lines below
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);  
        sort(p.begin(), p.end(), [](auto &a, auto &b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];
        });
        
        int r = 1;
        for(int i = 1, n = p.size(), c = p[0][1]; i < n; i++) {
            if(p[i][0] <= c) 
                c = min(c, p[i][1]);
            else {
                r++;
                c = p[i][1];
            }
        }
        return r;
    }
    */
};
