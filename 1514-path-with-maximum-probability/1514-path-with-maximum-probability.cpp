class Solution {
public:
    typedef pair<double, int> P;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,  vector<pair<int, double>>>adjList;
        
        vector<double>result(n, 0.0);
        
        // make adjacency list 
        for(int i=0; i<edges.size(); i++){
            int u= edges[i][0];
            int v= edges[i][1];
            double prob = succProb[i];
            
            adjList[u].push_back({v, prob});
             adjList[v].push_back({u, prob});
        }
        
        priority_queue<P>pq;
        
        // prob from to start = 1   
        result[start_node] =1;
        pq.push({1.0, start_node});
        
        while(!pq.empty()){
            int currNode = pq.top().second;
            double currProb = pq.top().first;
            
            pq.pop();
            
            for(auto &neigh: adjList[currNode]){
                int adjNode = neigh.first;
                double adjProb = neigh.second;
                
                if(result[adjNode] < (currProb*adjProb)){
                    result[adjNode] = currProb*adjProb;
                    pq.push({result[adjNode], adjNode});
                }  
            }
        }
         return result[end_node];
    }
};

