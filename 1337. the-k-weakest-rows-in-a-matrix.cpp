class Solution {
public:
    //sol 1
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ret;
        for(int i = 0;i< mat.size();i++){
            mat[i].push_back(i);
        }
        // sort in the first element of each vector!!! should to know about sort function of c++
        sort(mat.begin(),mat.end());
            
        for(int i = 0;i < k ;i++){
            ret.push_back(mat[i][mat[0].size()-1]);
        }
        
//         for(int i = 0;i< mat.size();i++){
//             for(int j = 0 ; j < mat[0].size();j++){
                
//                 cout<< mat[i][j];
//             }
//             cout<< endl;
//         }
        return ret;
    }

    
};
