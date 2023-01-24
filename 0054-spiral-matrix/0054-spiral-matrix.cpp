class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col =matrix[0].size();
        vector<int>ans;
        int startRow=0, startCol=0, endRow=row-1, endCol=col-1;
        int count=0, total = row*col;
        while(count<total){
          for(int i=startCol; count<total && i<=endCol; i++){
              ans.push_back(matrix[startRow][i]);
               count++;
          }  
            startRow++;
             for(int j=startRow; count<total && j<=endRow; j++){
              ans.push_back(matrix[j][endCol]);
                  count++;
          }  
            endCol--;
             for(int i=endCol; count<total && i>=startCol; i--){
              ans.push_back(matrix[endRow][i]);
                  count++;
          }  
            endRow--;
              for(int j=endRow; count<total && j>=startRow; j--){
              ans.push_back(matrix[j][startCol]);
                   count++;
          }  
            startCol++;
           
        }
        return ans;
    }
};