class Solution {
public:
    #define P pair<int, pair<int, int>>
    vector<vector<int>>directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n=grid[0].size();
        
        vector<vector<int>>results(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>>pq;
        
        results[0][0] = 0;
        
        pq.push({0, {0, 0}});
        while(!pq.empty()){
          auto curr= pq.top();
            pq.pop();
            
            int d = curr.first;
            int i= curr.second.first;
            int j= curr.second.second;
            
            for(auto dir: directions){
                int x = i+ dir[0];
                int y= j+ dir[1];
                
                if(x<0 || x>=m || y<0 || y>=n){
                    continue;
                }
                
                int wt = (grid[x][y] ==1)?1:0;
                if((d+wt) < results[x][y]){
                    results[x][y] = d+ wt;
                    pq.push({(d+wt), {x,y}});
                }
            }
        }
        return results[m-1][n-1];
    }
};