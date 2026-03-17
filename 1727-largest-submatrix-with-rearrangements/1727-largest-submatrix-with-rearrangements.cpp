class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int mxArea = INT_MIN;
        for(int row=0; row<rows; row++){
           for(int col = 0; col<cols; col++){
              if(matrix[row][col] ==1 && row>0){
                matrix[row][col]+= matrix[row-1][col];
              }
           }
          
          vector<int>heights = matrix[row];
          sort(heights.begin(), heights.end(), greater<int>());
          for(int col=0; col<cols; col++){
            int base = col + 1;
            int height = heights[col];
            mxArea = max(mxArea, (base*height));
          }
        }
       return mxArea;
    }
};
