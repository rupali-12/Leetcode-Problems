class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int mnAns=-1;
        unordered_map<int, vector<pair<int, int>>>adjList;
        for(auto flight: flights){
            int u= flight[0];
             int v= flight[1];
             int price= flight[2];
            adjList[u].push_back({v, price});
        }
        
        // {stops, {node, dist}}
        queue<pair<int, pair<int, int>>>q;
        q.push({0, {src, 0}});
        vector<int>dist(n, INT_MAX);
        dist[src]=0;
        while(!q.empty()){
            auto it= q.front();
              q.pop();
            int stops= it.first;
            int node= it.second.first;
            int cost = it.second.second;
            
            if(stops>k) continue;
            
            for(auto neigh: adjList[node]){
                int adjNode= neigh.first;
                int edWeight =neigh.second;
                if(cost + edWeight < dist[adjNode]&& stops<=k){
                    dist[adjNode] = cost + edWeight;
                    q.push({stops+1, {adjNode, dist[adjNode]}});
                }
            }
        }
        
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];

    }
};