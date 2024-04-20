class Solution {
public:
    int m, n;
     vector<vector<int>>ans;
    vector<vector<int>>directions= {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    void dfs(vector<vector<int>>& land, int i, int j, int &r2, int &c2){
       // mark as visited 
        land[i][j]=0;
        
        r2= max(i, r2);
        c2= max(j, c2);
        
        for(auto &dir: directions){
            int r= i+dir[0];
            int c= j+dir[1];
             if(r>=0 && c>=0 && r<m && c<n && land[r][c]==1 ){
            dfs(land, r, c, r2, c2);
        }
        }
    }
    
    void bfs(vector<vector<int>>& land, int i, int j, int &r2, int &c2){
        queue<pair<int, int>>q;
        q.push({i, j});
        land[i][j]=-1;
        
        while(!q.empty()){
            auto front= q.front();
            q.pop();
            
             r2= max(front.first, r2);
             c2= max(front.second, c2);
            for(auto dir:directions){
                int r= front.first + dir[0];
                int c= front.second + dir[1];
                
                if(r>=0 && c>=0 && r<m && c<n && land[r][c]==1){
                    q.push({r, c});
                    land[r][c]=-1;
                }
            }
        }
        return;
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m= land.size(), n= land[0].size();
        
        // // Approach-1: DFS 
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(land[i][j]==1){
        //             int r1=i, c1=j, r2=-1, c2=-1;
        //             dfs(land, i, j,  r2, c2);
        //             ans.push_back({r1, c1, r2, c2});
        //         }
        //     }
        // }
        
        // Approach-2: BFS 
         for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(land[i][j]==1){
                    int r1=i, c1=j, r2=-1, c2=-1;
                    bfs(land, i, j,  r2, c2);
                    ans.push_back({r1, c1, r2, c2});
                }
            }
        }
        return ans;
    }
};