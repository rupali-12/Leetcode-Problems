class Solution {
public:
    void dfs(int node, vector<vector<int>>&adj, vector<bool>&vis, int &vert, int &edges){
        vis[node]=true;
       vert++;
       edges+= adj[node].size();

       for(auto neigh: adj[node]){
          if(!vis[neigh]){
            dfs(neigh, adj, vis, vert, edges);
          }
       }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &e: edges){
            int u = e[0];
            int v = e[1];
           adj[u].push_back(v);
           adj[v].push_back(u);
        }
        vector<bool> vis(n, false);
        int ans=0;
        for(int i=0; i<n; i++){
           if(vis[i]) continue;

           int vert =0;
           int edges =0;
           dfs(i, adj, vis, vert, edges);

           edges/=2;  // as every edge count twice so 
           if(edges == vert*(vert-1)/2) ans++;
        }
        return ans;
    }
};