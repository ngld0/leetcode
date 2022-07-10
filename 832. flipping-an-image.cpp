class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        // Time O (n^2);space O(1)
        for(int im = 0;im<image.size();im++){ // reverse each row;
            reverse(image[im].begin(),image[im].end());
            for(int i = 0; i < image[im].size();i++){ // invert the image
                if(image[im][i] == 1) 
                    image[im][i] = 0;
                else 
                    image[im][i] = 1;
            }
        }
        return image;
    }
};
