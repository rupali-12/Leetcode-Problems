class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        
        queue<pair<pair<int, int>, int>>q;
    // int vis[n][m];
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({{i, j}, 0});
                    vis[i][j]=2;
                }
            }
        }
        
        int time=0;
        int delRow[]={-1, 0, 1, 0};
        int delCol[]= {0, 1, 0, -1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c =q.front().first.second;
            int t = q.front().second;
           // time= max(time, t);
            time=t;
            q.pop();
            
            for(int i=0; i<4; i++){
                int neighRow = r + delRow[i];
                 int neighCol = c + delCol[i];
                if(neighRow>=0 && neighRow<n && neighCol>=0 && neighCol<m && vis[neighRow][neighCol]!=2 && grid[neighRow][neighCol]==1){
                    q.push({{neighRow, neighCol}, t+1});
                    vis[neighRow][neighCol]=2;
                }
            }   
        }
        
        // check if all fresh oranges were converted into rotten or not
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]!=2 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
};