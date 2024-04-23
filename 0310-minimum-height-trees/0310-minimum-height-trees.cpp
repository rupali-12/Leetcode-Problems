class Solution {
public:
    unordered_map<int, vector<int>>adjList;
    vector<int>indegree;
    vector<int>ans;
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        indegree.resize(n);
        for(auto edge: edges){
            int u= edge[0];
            int v= edge[1];
            indegree[u]++;
            indegree[v]++;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        queue<int>q;
        for(int i=0; i<n; i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }
        
        while(n>2){   // atmost two nodes can be possible as answer
            int size= q.size();
            n-= size;  // update size of n as we will stop when only two nodes are present in graph i.e n=2;
            while(size--){
                int u= q.front();
                q.pop();
                
                for(auto &v: adjList[u]){
                    indegree[v]--;
                    if(indegree[v]==1){
                        q.push(v);
                    }
                }
            }
        }
        
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
        
    }
};