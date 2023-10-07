//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void topologicalSort(int node, unordered_map<int, list<pair<int, int>>>&adjList, 
    unordered_map<int, bool>&visited, stack<int>&topoSortOrder){

        visited[node]=true;

        for(auto neigh: adjList[node]){
            if(!visited[neigh.first]){
                topologicalSort(neigh.first, adjList, visited, topoSortOrder);
            }
        }
        topoSortOrder.push(node);
        return;
    }
    
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        // step-1: Make adjList 
    unordered_map<int, list<pair<int, int>>>adjList;
    for(int i=0; i<m; i++){
        int u= edges[i][0];
        int v= edges[i][1];
        int weight= edges[i][2];
 
      pair<int, int>p= make_pair(v, weight);
        adjList[u].push_back(p);
    }
     
     unordered_map<int, bool>visited;
     stack<int>topoSortOrder;
     
    // do dfs 
    for(int i=0; i<n; i++){
        if(!visited[i]){
            topologicalSort(i, adjList, visited, topoSortOrder);
        }
    }

    // shortest path 
    vector<int>dist(n, INT_MAX);
    dist[0] = 0;   //src=0 given
    while(!topoSortOrder.empty()){
        int top = topoSortOrder.top();
        topoSortOrder.pop();
        if(dist[top]!=INT_MAX){
            // precess neighbour
            for(auto neigh: adjList[top]){
                // neigh-> (node, weight)
               if(dist[top]+ neigh.second < dist[neigh.first]){
                   dist[neigh.first] = dist[top] + neigh.second;
               }

            }
        }
    }

    // set -1 to those whose dist= INT_MAX;
    for(int i=0; i<n; i++){
        if(dist[i]==INT_MAX){
            dist[i]=-1;
        }
    }

      return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends