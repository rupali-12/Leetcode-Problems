class Solution {
public:
    
    void dfs(int u,  unordered_map<int, vector<int>>&adj, stack<int>&st, vector<int>&visited, bool &cycle){
        // mark ongoing dfs 
        visited[u]=1;
        
        // process neigh 
        for(int v: adj[u]){
            if(visited[v]==0){
                dfs(v, adj, st, visited, cycle);
            }
            else if(visited[v]==1){   // is cycle exist 
                cycle= true;
                return;
            }
        }
        
        // mark visited 
        visited[u]=2;
        st.push(u);
    }
    
    // TopoSort 
    vector<int>topoSort(vector<vector<int>>&edges,int &k){
        // make adjacency matrix
        unordered_map<int, vector<int>>adj;
        for(auto edge: edges){
            int u= edge[0];
            int v= edge[1];
            
            adj[u].push_back(v);
        }
        
        stack<int>st;     // u-> v
        vector<int>order;
        // stack--> {u, v2, v1, v}
        // order-->  u->v2->v1->v 
        
        // visited[i] = 0; /// means not visited 
        // visited[i] = 1; /// means DFS ongoing on this node  
        // visited[i] = 2; /// means  visited 
        vector<int>visited(k+1, 0);  // k->1,2,3,/......k
        bool cycle= false;
        for(int u=1; u<=k; u++){
            if(visited[u]==0){
                dfs(u, adj, st, visited, cycle);
                if(cycle==true){
                    return {};
                }
            }
        }
        
        while(!st.empty()){
            order.push_back(st.top());
            st.pop();
        }
        
        return order;
    }
    
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        // step-1: Find topological order 
        vector<int>topoRow = topoSort(rowConditions, k);
        vector<int>topoCol = topoSort(colConditions, k);
        
        vector<vector<int>>ans(k, vector<int>(k, 0));
        
        if(topoRow.empty() || topoCol.empty()) return {};
        
        for(int i=0; i<k; i++){
            for(int j=0; j<k; j++){
                if(topoRow[i]==topoCol[j]){
                    // [i][j]
                    ans[i][j] = topoRow[i];  
                }
            }
        }
      
        
        return ans;
    }
};