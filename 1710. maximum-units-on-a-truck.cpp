class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n =  boxTypes.size();
        
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &a, const vector<int> &b){
           return a[1] > b[1]; 
        });
        int i = 0, boxes = 0;
        while(truckSize > 0 && i < n){
            int tt = truckSize;
            truckSize -= boxTypes[i][0];
            if(truckSize > 0){
                boxes += boxTypes[i][0] * boxTypes[i][1];
            }else
                boxes += tt * boxTypes[i][1];
            
            i++;
        }
        
        return boxes;
        
        
    }
};
