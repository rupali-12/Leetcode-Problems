class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        // cumulative row 
        int R= matrix.size();
        int C= matrix[0].size();
        for(int row=1; row<R; row++){
            for(int col=0; col<C; col++){
                if(matrix[row][col]!=0){
                    matrix[row][col] += matrix[row-1][col];
                }
            }
        }
        
        
        int maxArea=INT_MIN;
        for(int row=0; row<R; row++){
            sort(matrix[row].begin(), matrix[row].end(), greater<int>());
            for(int col=0; col<C; col++){
                int len = col+1;
                int currArea = len*matrix[row][col];
                maxArea= max(maxArea, currArea);
            }
        }
        return maxArea;
    }
};