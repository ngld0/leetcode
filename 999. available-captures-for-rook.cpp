class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        //Step 1. get the position of the rook
        int col = 0, row= 0, captures = 0; // saving the position of rook;
        for(int i = 0; i < 8;i++){
            for(int j = 0; j < 8;j++){
                if(board[i][j] == 'R'){
                    row = i;
                    col= j;
                    break;
                } 
            }
        }
        //Step 2. moving to the upper of the rook
        for(int i = row -1 ;i>= 0 && board[i][col] != 'B';i--){
            if(board[i][col] =='p') {
                captures++;
                break;
            }
            //if(board[i][col] == 'B') break;
        }
        
        //Step 3. moving to the down of the rook
        for(int i = row + 1 ;i< 8 && board[i][col] != 'B' ;i++){
            if(board[i][col] =='p') {
                captures++;
                break;
            }
            //if(board[i][col] == 'B') break;
        }
        //Step 4. moving to the left of the rook
        for(int i = col - 1 ; i>= 0 && board[row][i] != 'B'; i--){
            if(board[row][i] =='p'){
                captures++;
                break;
            } 
            //if(board[row][i] == 'B') break;
        }
        //Step 5. moving to the right of the Rook
        for(int i = col + 1 ; i< 8 && board[row][i] != 'B'; i++){
            if(board[row][i] =='p') {
                captures++;
                break;
            }
            //if(board[row][i] == 'B') break;
        }
        
        
        return captures;
    }
};
