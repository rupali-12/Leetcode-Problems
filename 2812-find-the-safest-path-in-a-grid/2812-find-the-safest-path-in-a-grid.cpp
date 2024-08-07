class Solution {
public:
    int n;
      vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    
    void multisourceBFS( vector<vector<int>>&disNearestThief,  vector<vector<int>>&grid,  vector<vector<bool>>&vis, queue<pair<int, int>>que){
        int level=0;
        while(!que.empty()){
            int size= que.size();
            while(size--){
                int curr_i = que.front().first;
                int curr_j = que.front().second;
            que.pop();
               
                disNearestThief[curr_i][curr_j] = level;
                
                //push neipghbour in queue
                for(auto dir: direction){
                    int new_i = curr_i + dir[0];
                    int new_j = curr_j + dir[1];
                    
                    if(new_i<0 || new_i >=n || new_j<0 || new_j >=n || vis[new_i][new_j]){
                        continue;
                    }
                    
                    que.push({new_i, new_j});
                    vis[new_i][new_j] =true;
                }
            }
            level++;
        }
        return;
    }
    
    
    bool check(vector<vector<int>>&disNearestThief, int safeFactor){
      vector<vector<bool>>vis(n, vector<bool>(n, false));
        queue<pair<int, int>>que;
        
        // {0,0} -->{n-1, n-1}
        que.push({0, 0});
        vis[0][0] = true;
        
        if(disNearestThief[0][0]<safeFactor){
            return false;
        }
        
        while(!que.empty()){
            int curr_i = que.front().first;
            int curr_j = que.front().second;
            que.pop();
            if(curr_i== n-1 && curr_j == n-1){
                return true;
            }
            
            // check neighbour 
            for(auto &dir: direction){
                int new_i = curr_i + dir[0];
                int new_j = curr_j + dir[1];
                
                // proceed only when 
                if(new_i>=0 && new_i <n && new_j >=0 && new_j <n && !vis[new_i][new_j]){
                   if(disNearestThief[new_i][new_j] < safeFactor){
                        continue;
                   }
                    
                    que.push({new_i, new_j});
                    vis[new_i][new_j] = true;
                }
            }
        }
        
        return false;
    }
    
    
    

    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n= grid.size();
        
        // step-1: Precalculation of disNearestThief for each cell
        vector<vector<int>>disNearestThief(n, vector<int>(n, -1));
        vector<vector<bool>>vis(n, vector<bool>(n, false));
        queue<pair<int, int>>que;
        
        // Push all theif position in queue
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    que.push({i, j});
                    vis[i][j]=true;
                }        
            }
        }
        
        // multisource BFS
        multisourceBFS(disNearestThief, grid, vis, que);
       
        
        // Step-2: Apply Binary Search on Safeness factor 
        int l=0, r= 400;    // As 1 <= grid.length == n <= 400
        int ans=0;
       while(l<=r){
            int mid = l + ((r-l)/2);
           //Now check if ther is any path existing in which every cell value >= mid
           if(check(disNearestThief, mid)){
               ans= mid;
               l= mid+1;
           }
           else{
               r= mid-1;
           }
       }
        return ans; 
    }
};
    
    
