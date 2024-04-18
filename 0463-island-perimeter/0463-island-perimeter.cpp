class Solution {
public:
     int row, col;
    int ans=0;
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i==row || j==col || grid[i][j]==0){
            ans++;
            return;
        }
        if(grid[i][j]==-1) return;
        
        grid[i][j]=-1;  // avoid overflow
        
         dfs(grid, i-1, j);
         dfs(grid, i+1, j);
         dfs(grid, i, j-1);
         dfs(grid, i, j+1);
    }
    
    int bfs(vector<vector<int>>& grid, int i, int j){
        int peri=0;
        queue<pair<int, int>>q;
        q.push({i, j});
        grid[i][j]=-1;
        vector<vector<int>>direction={{1,0},{-1,0}, {0,1},{0,-1}};
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            for(auto &dir: direction){
                int new_i= front.first + dir[0];
                int new_j= front.second + dir[1];
                
                if(new_i<0 || new_i>=row || new_j<0 || new_j >=col || grid[new_i][new_j]==0){
                    peri++;
                }
                else if(grid[new_i][new_j] == -1){
                    continue;
                }
                else{
                    q.push({new_i, new_j});
                    grid[new_i][new_j] = -1;
                }
            } 
        }
        return peri;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
       row = grid.size();
        col= grid[0].size();
        
        // // Approach-1: DFS
        // for(int i=0; i<row; i++){
        //     for(int j=0; j<col; j++){
        //         if(grid[i][j]==1){
        //             dfs(grid, i, j);
        //         }
        //     }
        // }
        // return ans;
        
        // // Approach-2: BFS
        // for(int i=0; i<row; i++){
        //     for(int j=0; j<col; j++){
        //         if(grid[i][j]==1){
        //             return bfs(grid, i, j);
        //         }
        //     }
        // }
         // return 0;
        
        // Approach-3: Matrix Traversal
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==0) continue;
                
                if(j+1>=col || grid[i][j+1]==0){
                    ans++;
                }
                if(j-1<0 || grid[i][j-1]==0){
                    ans++;
                }
                if(i+1>=row || grid[i+1][j]==0){
                    ans++;
                }
                if(i-1<0 || grid[i-1][j]==0){
                    ans++;
                }
            }
        }
        return ans;
       
    }
};