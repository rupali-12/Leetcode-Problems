class Solution {
public:
    #define P pair<int, int>
    
    void dijkstra(int n, unordered_map<int, vector<P>>&adj, vector<int>&result, int src){
        // <dist, node>
        priority_queue<P, vector<P>, greater<P>>pq;
        pq.push({0, src});
        fill(result.begin(), result.end(), INT_MAX);
        result[src]=0;
        
        while(!pq.empty()){
            int d=  pq.top().first;
            int node= pq.top().second;
            pq.pop();
            
            for(auto &p: adj[node]){
                int neigh =p.first;
                int dist = p.second;
                if(d+ dist < result[neigh]){
                    result[neigh]= d+dist;
                    pq.push({d+dist, neigh});
                }
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>SPM(n, vector<int>(n, 1e9+7));
        
        // Shortest distance from node to itself 
        for(int i=0; i<n; i++){
            SPM[i][i]=0;
        }
        
        unordered_map<int, vector<P>>adj;
        for(int i=0; i<edges.size(); i++){
            int u= edges[i][0];
            int v= edges[i][1];
            int w= edges[i][2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        for(int i=0; i<n; i++){
            dijkstra(n, adj, SPM[i], i);    
        }
        
        // iterate thorugh SPM and find leastReachableCount 
        long leastReachableCount= INT_MAX;
        int resultCity= -1;
        for(int i=0; i<n; i++){
            int count=0;
            for(int j=0; j<n; j++){
                if(i!=j  && SPM[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<= leastReachableCount){
                leastReachableCount= count;
                    resultCity= i;
            }
        }
        
        return resultCity;
    }
};