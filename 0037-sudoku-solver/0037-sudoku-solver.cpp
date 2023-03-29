class Solution {
public:
    bool ifSafe(int row, int col, vector<vector<char>>&board, char val){
   for(int i=0; i<9; i++){
        // for row
        if(board[row][i]==val){
            return false;
        }
         // for column
        if(board[i][col]==val){
            return false;
        }
         // for matrix
         int r = 3*(row/3) + i/3;
          int c = 3*(col/3) + i%3;
        if(board[r][c]==val){
            return false;
        }
   } 
    return true;
}
    bool solve(vector<vector<char>>&board){
    int n= board.size();   //9
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            // check if cell is empty 
            if(board[row][col]=='.'){
                for(int val='1'; val<='9'; val++){
                    if(ifSafe(row, col, board, val)){
                        board[row][col]=val;
                // make recursive call for next solution 
                    bool nextSol = solve(board);
                    if(nextSol){
                        return true;
                    } else {
                        // if next sol not possible then backtrack 
                      board[row][col]='.';
                    }
                    }
                }
                return false;  // case when all value checked and sol not find til then , 
            }
        }
    }
    return true;  
}
    void solveSudoku(vector<vector<char>>& board) {
         solve(board);
    }
};