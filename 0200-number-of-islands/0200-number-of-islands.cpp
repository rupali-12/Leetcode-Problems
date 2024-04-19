class Solution {
public:
    int m, n;
    
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j<0 ||i==m || j==n|| grid[i][j]=='0') return;
        if(grid[i][j]==-1) return;
        
        grid[i][j]=-1;
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
    
    void bfs(vector<vector<char>>& grid, int i, int j){
         queue<pair<int, int>>q;
        vector<vector<int>>direction= {{-1, 0}, {1,0}, {0,-1}, {0,1}};
        q.push({i, j});
        grid[i][j]='$';
        
        while(!q.empty()){
            auto front =q.front();
            q.pop();
            
            for(auto &dir: direction){
                int new_i= front.first + dir[0];
                int new_j= front.second + dir[1];
                
                if(new_i<0 || new_j<0 || new_i==m || new_j==n || grid[new_i][new_j]!='1'){
                    continue;
                }
                
                else{
                    q.push({new_i, new_j});
                grid[new_i][new_j]='$';
                }
            }
        }
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
         m= grid.size();
         n= grid[0].size();
        int count=0;
        
        // // Approach-1:DFS 
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(grid[i][j]=='1'){
        //             dfs(grid, i, j);
        //             count++;
        //         }
        //     }
        // }
        
        // Approach-2: BFS
       for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1'){
                    bfs(grid, i, j);
                    count++;
                }
            }
        }
        
        
        return count;
    }
};