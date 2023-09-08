//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool isFound(vector<vector<char>>grid, vector<vector<int>>&ans,int i, int j, string word, int len, int x[], int y[], int row, int col){
   for(int dir= 0; dir<8; dir++){
       int i1=i, j1= j, k=0;
       int x1= x[dir], y1= y[dir];
       
       while(i1>=0 && i1<row&& j1>=0 && j1<col && k<len){
           if(word[k]==grid[i1][j1]){
               i1+= x1;
               j1+= y1;
               k++;
           }
           else{
               break;
           }
       }
       if(k==len){
           return true;
       }
   }
   return false;
}
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    vector<vector<int>>ans;
	    vector<int>temp(2);
	    int x[8]= {-1, 0, 1, 1, 1, 0, -1, -1};
	    int y[8]= {1, 1, 1, 0, -1, -1, -1, 0};
	    int row=grid.size(), col=grid[0].size();
	    int len= word.length();
       for(int i=0; i<row; i++){
           for(int j=0; j<col; j++){
               if(isFound(grid, ans, i, j, word, len, x, y, row, col)){
                   temp[0]= i;
                   temp[1]=j;
                   ans.push_back(temp);
               }
           }
       }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends