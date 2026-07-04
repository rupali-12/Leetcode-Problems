class Solution {
public:
  vector<pair<int,int>> adj[100001];
  void dfs(int node, vector<int>&vis, int &ans){
    vis[node]=1;
    for(auto &[nbr, dist]: adj[node]){
        ans = min(ans, dist);
        if(!vis[nbr]){
            dfs(nbr, vis, ans);
        }
    }
  }
    int minScore(int n, vector<vector<int>>& roads) {
        for(auto r: roads){
            int u = r[0];
            int v = r[1];
            int d = r[2];
            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }
       int ans = INT_MAX;
       vector<int>vis(n+1, 0);
     dfs(1, vis, ans);
     return ans;
    }
};