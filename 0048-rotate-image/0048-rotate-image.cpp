class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n= matrix.size();

        // first transpose 
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Then reverse columns
        for(int i=0; i<n; i++){
           for(int j=0; j<n/2; j++){
            swap(matrix[i][j], matrix[i][n-j-1]);
           }
        }
        return;
    }
};