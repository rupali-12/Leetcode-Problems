class Solution {
public:
    int timer=0;
    void dfs(int node, int parent,  vector<int>adj[], vector<bool>&vis, vector<int>&disc,
            vector<int>&low, vector<vector<int>>&bridges){
        vis[node]=1;
        low[node]= disc[node]=timer;
        timer++;
        
        // process adj node 
        for(auto neigh: adj[node]){
            if(neigh==parent) continue;
            if(vis[neigh]==0){      // not visited
                dfs(neigh, node, adj, vis, disc, low, bridges);
                low[node]= min(low[node], low[neigh]);
                
                // node---> can be neigh or not agr return krte time agr neigh ka low node k low se greater h to vo usk tk nhi pahuch sakta so this is case of back edge or bridge 
                if(low[neigh]>disc[node]){
                    bridges.push_back({neigh, node});
                }
                
            }
            else{
                low[node]= min(low[node], low[neigh]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>bridge;
        vector<int>adj[n];
        for(auto i: connections){
            int u= i[0];
            int v= i[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>disc(n);
        vector<int>low(n);
        vector<bool>vis(n, 0);
        dfs(0, -1, adj, vis, disc, low, bridge);
        return bridge;
        
    }
};