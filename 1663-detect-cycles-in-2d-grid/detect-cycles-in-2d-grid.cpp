class Solution {
public:
    int m, n;
    vector<vector<int>>vis;
    bool dfs(vector<vector<char>>& grid, int i, int j, int pi, int pj){
       vis[i][j]=1;  // mark visited
       int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};


       for(auto d: dir){
        int ni = i + d[0];
        int nj = j + d[1];

       if(ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
       if(grid[ni][nj] != grid[i][j]) continue;

        //   if visited and not parent means cycle exist
           if(vis[ni][nj] && !(ni==pi && nj==pj)){
            return true;
           }

        //    if not visited
        if(!vis[ni][nj]){
            if(dfs(grid, ni, nj, i, j)) return true;
        }
       }
       return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
         m= grid.size();
         n=grid[0].size();

        vis.assign(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j]){
                    if(dfs(grid, i, j, -1, -1)){
                    return true;
                }
                }
            }
        }
        return false;
    }
};