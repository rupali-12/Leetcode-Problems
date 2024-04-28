class Solution {
public:
    long root_result=0;
    vector<int>count;
    
    int dfs(unordered_map<int, vector<int>>&adjList, int curr_node, int prev_node, int curr_depth){
        int total_node=1;
        
        root_result+= curr_depth;
        
        for(auto &child: adjList[curr_node]){
            if(child == prev_node) continue;
            
            total_node+= dfs(adjList, child, curr_node, curr_depth+1);
        }
        count[curr_node] = total_node;
        return total_node;
    }
    
    void DFS(unordered_map<int, vector<int>>&adjList, int n, int parent, int prev_node, vector<int>&ans){
       for(auto child: adjList[parent]){
           if(child==prev_node) continue;
           
           // ans[child]= ans[parent] - count[child] + (n- count[child]);
           ans[child]= ans[parent] + n - (2*count[child]);
           DFS(adjList, n, child, parent, ans);
       }    
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
       count.resize(n, 0);
       unordered_map<int, vector<int>>adjList;
        for(auto edge: edges){
            int u=edge[0];
            int v=edge[1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        int prev_node=-1;
        int curr_depth=0;
        int curr_node= 0;
        dfs(adjList, curr_node, prev_node, curr_depth);
        
        vector<int>ans(n,0);
        ans[0]= root_result;
       DFS(adjList, n, 0, -1, ans);
        return ans;
    }
};