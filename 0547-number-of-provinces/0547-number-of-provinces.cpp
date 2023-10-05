class Solution {
public:
    void preparedAdjList(vector<vector<int>>& isConnected, int n, unordered_map<int, list<int>>&adjList){
     for(int i=0; i<n; i++){
         for(int j=0; j<n; j++){
             if(isConnected[i][j]==1 && i!=j){    // i=1 cannot make edge with j=1
                 adjList[i].push_back(j);
                 adjList[j].push_back(i);
             }
         }
     }
}
void dfs(int node, unordered_map<int, list<int>>&adjList, unordered_map<int, bool>&visited){
     visited[node]=1;

     for(auto i: adjList[node]){
         if(!visited[i]){
             dfs(i, adjList, visited);
         }
     }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
         unordered_map<int, list<int>>adjList;
    preparedAdjList(isConnected, n, adjList);
   int count=0;
   unordered_map<int, bool>visited;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            count++;
            dfs(i, adjList, visited);
        }
    }
    return count;
    }
};