class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // for cycles 
        // for(int i=0; i<n/2; i++){
        //     for(int j=i; j<n-i-1; j++){
        //         int temp =matrix[i][j];
        //         matrix[i][j]= matrix[n-j-1][i];
        //         matrix[n-j-1][i]= matrix[n-i-1][n-j-1];
        //          matrix[n-i-1][n-j-1] =matrix[j][n-i-1];
        //         matrix[j][n-i-1]= temp;
        //     }
        // }
        
        // Approach-2>>
        // find transpose of matrix 
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // for reversing the columns >>>
        for(int i=0; i<n; i++){
            for(int j=0; j<n/2; j++){
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }
    }
};