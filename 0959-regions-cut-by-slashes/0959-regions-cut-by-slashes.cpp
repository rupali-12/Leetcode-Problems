class Solution {
public:
    int rows, cols;
    
    void DFS(vector<vector<int>>&matrix, int i, int j){
       if(i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size() || matrix[i][j]==1){
           return;
       }    
        
        matrix[i][j]=1;   // Mark visited
        
        DFS(matrix, i-1, j);  // up
        DFS(matrix, i+1, j);  // down
        DFS(matrix, i, j-1);  // left
        DFS(matrix, i, j+1);  // right
    }
    
    int regionsBySlashes(vector<string>& grid) {
        rows = grid.size();
        cols= grid[0].size();
        
        vector<vector<int>>matrix(rows*3, vector<int>(cols*3, 0));
        
        // mapping of '\', '/'
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]=='/'){
                   matrix[i*3][j*3 + 2]=1;
                   matrix[i*3 + 1][j*3 + 1]=1;
                   matrix[i*3 + 2][j*3]=1;
                }
                else if(grid[i][j]=='\\'){
                   matrix[i*3][j*3]=1;
                   matrix[i*3 + 1][j*3 + 1]=1;
                   matrix[i*3 + 2][j*3 + 2]=1;
                 }
            }
        }
                        
        // call DFS to count regions (exact logic of number of island problem)
        int ans=0;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    DFS(matrix, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};