class Solution {
public:
typedef pair<int, int>P;
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<P>>adjList;
        for(auto &edge: edges){
            int u= edge[0];
            int v= edge[1];
            int w = edge[2];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, 2*w});  // reversed edge
        }

        priority_queue<P, vector<P>, greater<P>>pq;   // max-heap
       vector<int>result(n, INT_MAX);  // result[i] = distance of S=0 with node i
      result[0] = 0;
      pq.push({0, 0});

      while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(node ==n-1){
            return result[n-1];
        }

        for(auto &p: adjList[node]){
            int adjNode = p.first;
            int adjDis = p.second;

            if(d+adjDis < result[adjNode]){
                result[adjNode] =d + adjDis;
                pq.push({d+adjDis, adjNode});
            }
        }
      }
      return -1;
    }
};