class Solution {
public:
typedef tuple<int, int, int>T;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        unordered_map<int, vector<pair<int, int>>>adj;
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }

        priority_queue<T, vector<T>, greater<T>>pq;   // {dis, node, consCount}
        vector<vector<int>>result(n, vector<int>(k+1, INT_MAX));    // {node, consCount}
        result[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty()){
            auto [d, node, count] = pq.top();
            pq.pop();

            if(d > result[node][count]) continue;
            if(node == n-1)return d;

            for(auto vec: adj[node]){
                int adjNode = vec.first;
                int wt = vec.second;

                int newCount = (labels[node]==labels[adjNode])? count+1 : 1;
                if(newCount > k) continue;

                int newDis = d + wt;
                if(newDis < result[adjNode][newCount]){
                    result[adjNode][newCount] = newDis;
                    pq.push({newDis, adjNode, newCount});
                }
            }
        }
        return -1;
    }
};