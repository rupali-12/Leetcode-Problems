class Solution {
public:
    
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m= grid.size(), n= grid[0].size();
        vector<int>num1Row(m), num1Col(n);
        
//         // store sum of rows
//         for(int i=0; i<m; i++){
//             int sum=0;
//             for(int j=0; j<n; j++){
//                 if(grid[i][j]==1){
//                     sum+=grid[i][j];
//                 }
//             }
//             num1Row[i] = sum;
//         }
       
        
// //          // store sum of cols
//         for(int j=0; j<n; j++){
//             int sum=0;
//             for(int i=0; i<m; i++){
//                 if(grid[i][j]==1){
//                     sum+=grid[i][j];
//                 }
//             }
//             num1Col[j] = sum;
//         }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    num1Row[i]+= grid[i][j];
                    num1Col[j]+= grid[i][j];
                }
            }
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                // int diff = num1Row[i] + num1Col[j] -(n-num1Row[i]) - (m-num1Col[j]);
                int diff = 2*(num1Row[i] + num1Col[j]) -(m+n);
                grid[i][j] =diff;
            }
        }
        return grid;
    }
};