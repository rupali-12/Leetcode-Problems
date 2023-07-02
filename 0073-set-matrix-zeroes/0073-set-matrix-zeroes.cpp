class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // int col=1, rows =matrix.size(), cols = matrix[0].size();
        // for( int i=0; i<rows;i++){
        //     if(matrix[i][0]==0) col=0;
        //     for(int j=1; j<cols; j++){
        //         if(matrix[i][j]==0){
        //             matrix[i][0]= matrix[0][j]=0;
        //         } 
        //     }
        // }
        // for(int i=rows-1; i>=0; i--){
        //     for(int j=cols-1; j>=1; j--){
        //         if(matrix[i][0]==0 || matrix[0][j]==0){
        //             matrix[i][j]=0;
        //         }
        //     }
        //     if(col==0){
        //         matrix[i][0]=0;
        //     }
        // }
        
        
        // ***********************************************************
        bool row=0, col=0;
        int rows= matrix.size(), cols= matrix[0].size();
        
        // Step-1: Check if there exist any zero in first row/col
        for(int i=0; i<rows; i++){
            if(matrix[i][0]==0) col=true;
        }
        for(int i=0; i<cols; i++){
            if(matrix[0][i]==0) row=true;
        }
        
        // step-2> Process the rem matrix 
        for(int i=1; i<rows; i++){
            for(int j=1; j<cols; j++){
                if(matrix[i][j]==0){
                   matrix[i][0]= matrix[0][j]=0; 
                }
            }
        }
        
        // step-3: process first row/col 
        for(int i=1; i<rows; i++){
            if(matrix[i][0]==0){
                for(int j=0; j<cols; j++){
                matrix[i][j]=0;
            }
            }
        }
        
         for(int j=1; j<cols; j++){
            if(matrix[0][j]==0){
                for(int i=0; i<rows; i++){
                matrix[i][j]=0;
            }
            }
        }
        
        // step-4 : last check if row or col is zero or not 
        if(col){
            for(int i=0; i<rows; i++){
                matrix[i][0]=0;
            }
        }
         if(row){
            for(int j=0; j<cols; j++){
                matrix[0][j]=0;
            }
        }
        return;
    }
};