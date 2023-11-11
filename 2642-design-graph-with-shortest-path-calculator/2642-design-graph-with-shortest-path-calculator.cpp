class Graph {
public:
    
    // Approach-1: Dijstra's Algorithm 
            vector<vector<pair<int, int>>>adj;
    Graph(int n, vector<vector<int>>& edges) {
       adj.resize(n);
        for(auto edge: edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        // <cost, node>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<int>cost(adj.size(), INT_MAX);
        
        pq.push({0, node1});
        cost[node1]= 0;
       while(!pq.empty()){
           auto currCost= pq.top().first, currNode= pq.top().second;
           pq.pop();
            for(auto neigh: adj[currNode]){
               if(cost[neigh.first] > cost[currNode] + neigh.second){
                  cost[neigh.first] = cost[currNode] + neigh.second; 
                   pq.push({cost[neigh.first], neigh.first});
               }
           }
       }
        return cost[node2]==INT_MAX?-1: cost[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */