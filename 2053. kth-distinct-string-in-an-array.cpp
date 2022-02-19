class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> map;
        for(auto ar : arr){
            map[ar]++;
        }
        int i =0;
        for(auto ar: arr){
            
            if(map[ar]==1){
                i++;
                if(i==k) return ar;
            }
        }
        
        return "";
    }
};
