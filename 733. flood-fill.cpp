class Solution {
public:
    //recursive step-by-step
    void recursive(vector<vector<int>>& image, int sr, int sc, int color, int oldColor,int mrows, int ncolumns){
        image[sr][sc] = color; // Modifying on image variable, then space O(1)
 
        
        if(sc > 0 && image[sr][sc-1] == oldColor){ //left of column sc of row sr (the column in the left)
             recursive(image, sr, sc-1, color, oldColor, mrows, ncolumns);
        }
        
        if(sc < (ncolumns-1) && image[sr][sc+1] == oldColor){ //right of the column sc of row sr
            recursive(image, sr, sc+1, color, oldColor, mrows, ncolumns);
        }
        
        if(sr > 0 && image[sr-1][sc] == oldColor){ //previous rows
            recursive(image, sr-1, sc, color, oldColor, mrows, ncolumns);
        }
        
        if(sr < (mrows -1) && image[sr+1][sc] == oldColor){ //following rows
            recursive(image, sr+1, sc, color, oldColor, mrows, ncolumns);
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        if(image[sr][sc] == color) // if the color are the same, then shouldnot fill;
            return image; 
        recursive(image, sr, sc, color, image[sr][sc], m,n); // call the recursive function
        return image;
    }
    
};
