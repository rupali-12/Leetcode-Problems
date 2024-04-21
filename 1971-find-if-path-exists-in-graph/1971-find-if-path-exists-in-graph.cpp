class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>&adjList, int des, vector<bool>&vis, int node){
        if(node==des){
            return true;
        }
        
        // mark visited
        vis[node]=true;
        for(auto &neigh: adjList[node]){
            if(!vis[neigh]){
                if(dfs(adjList, des, vis, neigh)){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>>adjList;
        for(int i=0; i<edges.size(); i++){
            int u= edges[i][0];
            int v= edges[i][1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
       vector<bool>vis(n);
        
        // // Approach-1: dfs 
        // return dfs(adjList, destination, vis,source);
        
        // Approach-2: BFS 
        queue<int>q;
        q.push(source);
        vis[source]=true;
        
        while(!q.empty()){
            int node= q.front();
            q.pop();
            
            if(node==destination){
                return true;
            }
            
            for(int neigh: adjList[node]){
                if(!vis[neigh]){
                    vis[neigh]=true;
                    q.push(neigh);
                }
            }       
        }
        return false;
        
        
    }
}; 