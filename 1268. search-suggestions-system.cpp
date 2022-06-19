class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        int n = products.size();
        
        vector<vector<string>> ret;
        
        string search = "";
        
        auto it = products.begin();
        
        for(int i = 0 ; i < searchWord.length();i++){
            search += searchWord[i];
            
            vector<string> suggestedWord;
            
            it = lower_bound(it, products.end(), search); //return an iterator pointing to the first element in the range [first, last) which has a value not less than val.
            for(int j = 0; it+j != products.end() && j <3 ;j++){

                string& cmp = *(it + j);
                
                if(cmp.find(search) ) break;
                
                suggestedWord.push_back(cmp);
                
               
            }
            ret.push_back(suggestedWord);
        }
        return ret;
    }
};
