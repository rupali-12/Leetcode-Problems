class Solution {
public:
    int m, n;
    void flipRow(vector<vector<int>>& grid, int row){
        for(int i=0; i<n; i++){
            grid[row][i]^=1;
        }
        return;
    }
    void flipCol(vector<vector<int>>& grid, int col){
        for(int i=0; i<m; i++){
            grid[i][col]^=1;
        }
        return;
    }
    int matrixScore(vector<vector<int>>& grid) {
         m= grid.size();
        n= grid[0].size();
        
        // For Row, check if grid[i][0]=0 then flip Row 
        for(int i=0; i<m; i++){
            if(grid[i][0]==0){
               flipRow(grid, i); 
            }
        } 
        
        // For Column if number of 1's less than 0's then flipColumn
        for(int i=0; i<n; i++){
            int count1=0;
            for(int r=0; r<m; r++){
                if(grid[r][i]==1) count1++;
            }
            
            if(count1 < (m-count1)){
                flipCol(grid, i);
            }
        }
        
        int ans=0;
        // // way-1: using power function 
        // for(int i=0; i<m; i++){
        //     int num=0, power=0;
        //     for(int j=0; j<n; j++){
        //         num+= pow(2, power)*grid[i][n-1-j];
        //         power++;
        //     }
        //     ans+= num;
        // }
        
        // way-2: using xor 
        for(int i=0; i<m; i++){
            int num=0;
            for(int j=0; j<n; j++){
                if(grid[i][n-1-j]){
                    num = num | grid[i][n-1-j]<<j;
                }
            }
            ans+= num;
        }
        
        return ans;
    }
};


