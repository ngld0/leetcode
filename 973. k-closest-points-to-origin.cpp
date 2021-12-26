class Solution {
public:
    
    static bool cmp(pair<int, float>& a,
         pair<int, float>& b)
    {
        return a.second <= b.second;
    }
   vector<int> sorting(unordered_map<int, float>& M)
    {
       vector<int> sorted;
        // Declare vector of pairs
        vector<pair<int, float> > A;
       
        for (auto& it : M) {
            A.push_back(it);
        }        
        std::sort(A.begin(), A.end(), cmp);
         for (auto& it : A) {
             cout<<it.second<<endl;
             sorted.push_back(it.first);

         }
       return sorted;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        unordered_map<int, float> a_map; 
        vector<int> b_map;
         vector<vector<int>> ans;
        for(int i = 0 ; i < points.size();i++){
            a_map[i] = sqrt(points[i][0]* points[i][0] + points[i][1]*points[i][1]);
        }
        b_map = sorting(a_map);
        
        for(int i = 0 ; i < k ;i++){
            ans.push_back(points[b_map[i]]);
        }
       
       
        return ans;
    }
};
//better solution
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        return quickSelect(points, k);
    }
    
    vector<vector<int>> quickSelect(vector<vector<int>>& points, int k){
        int n = points.size();
        int left = 0;
        int right = n - 1;
        int pivotIndex = n;
        
        while(pivotIndex != k){
            pivotIndex = partition(points, left, right);
            if(pivotIndex < k){
                left = pivotIndex;
            } else {
                right = pivotIndex - 1;
            }
        }
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
    
    int partition(vector<vector<int>>& points, int left, int right){
        int mid = left + (right - left) / 2;
        int pivotDist = squaredDistance(points[mid]);
        while(left < right){
            if(squaredDistance(points[left]) >= pivotDist){
                swap(points[left], points[right]);
                right--;
            } else {
                left++;
            }
        }
        
        if(squaredDistance(points[left]) < pivotDist){
            left++;
        }
        return left;
    }
    
    int squaredDistance(vector<int>& point){
        return point[0] * point[0] + point[1] * point[1];
    }
};
