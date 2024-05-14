class Solution {
public:
    int m, n;
    vector<int>row = {0, 0, -1, 1};
    vector<int>col = {-1, 1, 0, 0};
    int solve(vector<vector<int>>& grid, int currx, int curry, vector<vector<bool>>&vis){
        if(currx<0 || curry<0 || currx>=m || curry>=n || grid[currx][curry]==0 || vis[currx][curry]) return 0;
        vis[currx][curry] =true;
        int localMxSum=0;
       for(int i=0; i<4; i++){
           int newx =  currx + row[i];
           int newy= curry + col[i];
           localMxSum =max(localMxSum, grid[currx][curry] + solve(grid, newx, newy, vis));
          
       }
         vis[currx][curry]=false;
        
        return localMxSum;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        m= grid.size(), n= grid[0].size();
        int mxSum=INT_MIN;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                vector<vector<bool>>vis(m, vector<bool>(n, false));
                mxSum = max(mxSum, solve(grid, i, j, vis));
            }
        }
        
        return mxSum;
    }
};