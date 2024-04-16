class Solution {
public:
     void flipRow(vector<vector<int>>& grid,int r){
        int c= grid[0].size();
        for(int i=0; i<c; i++){
            grid[r][i]^=1;
        }
    }
      void flipCol(vector<vector<int>>& grid,int c){
        int n= grid.size();
        for(int r=0; r<n; r++){
            grid[r][c]^=1;
        }
    }
    int matrixScore(vector<vector<int>>& grid) {
        int m= grid.size(), n= grid[0].size();
        
        // check for Row, flip row when grid[i][0]=0(make msb as 1 if not)
        for(int i=0; i<m; i++){
            if(grid[i][0]==0){
                flipRow(grid, i);
            }
        }
        
        // for column if number of ones is less than zeros then flip column 
        for(int c=0; c<n; c++){
            int count1=0;
            for(int r=0; r<m; r++){
                if(grid[r][c]==1) count1++;
            }
            if(count1< (m-count1)){
                flipCol(grid, c);
            }
        }
        int ans=0;
        
        // // Way-1: pow function
        // for(int i=0;i<m; i++){
        //     int num=0, power=0;
        //     for(int j=n-1; j>=0; j--){
        //        num+= pow(2, power) * grid[i][j];
        //         power++;
        //     }
        //     ans+= num;
        // }
        
        // Way-2: bit manipulation
        for(int i=0;i<m; i++){
            int num=0;
            // for(int j=n-1; j>=0; j--){
            //    if(grid[i][j]){
            //        num= num | grid[i][j]<<(n-j-1);
            //    }
            // Way-2
            for(int j=0; j<n; j++){
               if(grid[i][n-1-j]){
                   num= num | grid[i][n-1-j]<<j;
               }
            }
            ans+= num;
        }
        return ans;
        
    }
};