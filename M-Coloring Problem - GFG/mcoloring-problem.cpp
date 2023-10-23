//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(bool graph[101][101], int i, int j, int n, vector<int>&color){
        // check if I can assign color j to node i 
        // no other neighbour of i have same color j or not 
        
        for(int k=0; k<n; k++){
            if(graph[i][k]==1 && color[k]==j) return false;
        }
        return true;
    }
    
    bool solve(bool graph[101][101], int m , int n, int i, vector<int>&color){
        if(i==n) return true;
        
        for(int j= 0; j<m; j++){
            if(isSafe(graph, i, j, n, color)){
                color[i]=j;
                
                if(solve(graph, m, n, i+1, color)){
                    return true;
                }
                
                // if any call return false then backtrack 
                color[i]=-1;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        
        // color from 0 to m 
        vector<int>color(n, -1);     // n size as i use m colors but check color for ith node so size of color vector is n 
         int i=0;   // start node 
        return solve(graph, m , n, i, color);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends