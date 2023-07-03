class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        int totalFresh=0;
        
        queue<pair<pair<int, int>, int>>q;
    // int vis[n][m];
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({{i, j}, 0});
                    vis[i][j]=2;
                }
                if(grid[i][j]==1){totalFresh++;}
            }
        }
        
        int time=0, cnt=0;
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
                    vis[neighRow][neighCol]=2;\
                        cnt++;
                }
            }   
        }
        
        // check if all fresh oranges were converted into rotten or not
        // instead of this check we can count te fresh oranges when we put in queue and compare it with total fresh oranges if its not equal then return -1 
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         if(vis[i][j]!=2 && grid[i][j]==1){
        //             return -1;
        //         }
        //     }
        // }
        
        if(cnt!=totalFresh){
            return -1;
        }
        return time;
    }
};