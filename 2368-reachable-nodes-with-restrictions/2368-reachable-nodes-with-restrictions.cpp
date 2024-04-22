class Solution {
public:
    unordered_set<int>rest;
     int maxAns=1;  // 1 for 0(start node)
     unordered_map<int, vector<int>>adjList;
    vector<bool>vis;
    
    void dfs(int node){
        for(auto &x: adjList[node]){
            if(!vis[x] && rest.find(x)==rest.end()){
                vis[x]=true;
                dfs(x);
               maxAns++;   
            }
        }
        return;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
      for(auto x: restricted){
          rest.insert(x);
      }
        vis.resize(n);
       
        for(auto &edge: edges){
            int u= edge[0];
            int v= edge[1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        
       
        vis[0]=true;
        dfs(0);
       
        return maxAns;
    }
};