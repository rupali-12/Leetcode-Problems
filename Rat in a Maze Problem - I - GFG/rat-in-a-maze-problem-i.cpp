//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafe(int x, int y, int n,vector<string>&ans, vector<vector<int>> &m, 
    vector<vector<int>>&visited){
        
        if((x>=0 && x<n) && (y>=0 && y<n) && m[x][y]==1 && visited[x][y]==0){
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>> &m, int n,vector<string>&ans, int srcx, 
    int srcy,vector<vector<int>> &visited , string &path){
        if(srcx==n-1 && srcy==n-1){
            ans.push_back(path);
            return;
        }
         visited[srcx][srcy]=1;
        // 1. Down 
        int newx = srcx+1;
        int newy = srcy;
       
        if(isSafe(newx, newy, n, ans, m, visited)){
            path.push_back('D');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        // 2. Up
        newx = srcx-1;
        newy = srcy;
        if(isSafe(newx, newy, n, ans, m, visited)){
            path.push_back('U');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        // 3. Right 
         newx = srcx;
         newy = srcy+1;
        if(isSafe(newx, newy, n, ans, m, visited)){
            path.push_back('R');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        // 4. Left 
        newx = srcx;
         newy = srcy-1;
        if(isSafe(newx, newy, n, ans, m, visited)){
            path.push_back('L');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
       
        
        visited[srcx][srcy]=0;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
         vector<string>ans;
          int srcx=0, srcy=0;
        //  handle case when rat is at start position (0,0) 
        if(m[0][0]==0){
            return ans;
        }
        vector<vector<int>> visited = m;  
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                visited[i][j]=0;
            }
        }
        
        string path="";
        solve(m, n, ans, srcx, srcy, visited, path);
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends