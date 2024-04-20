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
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m= land.size(), n= land[0].size();
        
        // Approach-1: DFS 
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(land[i][j]==1){
                    int r1=i, c1=j, r2=-1, c2=-1;
                    dfs(land, i, j,  r2, c2);
                    ans.push_back({r1, c1, r2, c2});
                }
            }
        }
        return ans;
    }
};