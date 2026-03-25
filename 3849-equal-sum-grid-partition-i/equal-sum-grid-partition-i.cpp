class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m =grid.size(), n=grid[0].size();

        long long totalSum=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                totalSum+= grid[i][j];
            }
        }

        long long rowSum=0;
        for(int r=0; r<m-1; r++){
            for(int c=0; c<n; c++){
               rowSum+= grid[r][c];
            }
            if(rowSum == totalSum - rowSum) return true;
        }

        long long colSum=0;
        for(int c=0; c<n-1; c++){
            for(int r=0; r<m; r++){
               colSum+= grid[r][c];
            }
            if(colSum == totalSum - colSum) return true;
        }
       
       return false;
    }
};