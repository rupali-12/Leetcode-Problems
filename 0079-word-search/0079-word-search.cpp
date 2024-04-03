class Solution {
public:
    bool solve(int index, int i, int j, string word, vector<vector<char>>& board){
        if(index==word.length()) return true;
        if(i<0 || j<0 || i==board.size() || j==board[0].size()) return false;
        bool ans= false;
        if(word[index]==board[i][j]){
            board[i][j]='*' ;  // to avoid run time error
            ans= solve(index+1, i-1, j, word, board) || solve(index+1, i+1, j, word, board) || solve(index+1, i, j-1, word, board) || solve(index+1, i, j+1, word, board);
            
            board[i][j]= word[index];  // backtrack
        }
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n= board[0].size();
        int index=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(word[index]==board[i][j]){
                    if(solve(index, i, j, word, board)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};