//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int row  = grid.size();
        int col =  grid[0].size();
        queue<pair<pair<int, int>, int>>q;
       int vis[row][col];
    //   store all elements which is rotten initially 
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(grid[i][j]==2){
                q.push(make_pair(make_pair(i, j), 0));
                vis[i][j]=2;
            }
            else{
                vis[i][j]=0;
            }
        }
    }
    int tim=0;
    int delRow[]= {-1, 0, 1, 0};
    int delCol[]= {0, 1, 0, -1};
    while(!q.empty()){
        // queue<pair<pair<int, int>, int>>temp= q.front();
      auto temp=q.front();
        q.pop();
        int r= temp.first.first;
        int c= temp.first.second;
        int t= temp.second;
        tim=max(tim,t);
      for(int i=0; i<4; i++){
          int nrow= r + delRow[i];
          int ncol= c + delCol[i];
          if(nrow>=0 && nrow<row && ncol>=0 && ncol<col && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
              q.push({{nrow, ncol}, t+1});
              vis[nrow][ncol]=2;
          }
      }
    }
     for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(grid[i][j]==1 && vis[i][j]!=2){
               return -1;
            }
        }
    }
    return tim;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends