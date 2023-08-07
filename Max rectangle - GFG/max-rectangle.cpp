//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  vector<int>nextSmaller(int *arr, int n){
      stack<int>s;
      vector<int>ans(n);
      s.push(-1);
      for(int i=n-1; i>=0; i--){
          while(s.top()!=-1 && arr[s.top()]>=arr[i]){
              s.pop();
          }
          ans[i]= s.top();
          s.push(i);
      }
      return ans;
  }
  vector<int>prevSmaller(int *arr, int n){
      stack<int>s;
      vector<int>ans(n);
      s.push(-1);
      for(int i=0; i<n; i++){
          while(s.top()!=-1 && arr[s.top()]>=arr[i]){
              s.pop();
          }
          ans[i]= s.top();
          s.push(i);
      }
      return ans;
  }
  int largestArea(int *arr, int n){
      vector<int>next = nextSmaller(arr, n);
      vector<int>prev = prevSmaller(arr, n);
      int ans= INT_MIN;
     for(int i=0; i<n; i++){
          int len= arr[i];
      if(next[i]==-1){
          next[i]=n;
      }
      int breadth= next[i]-prev[i]-1;
      ans= max(ans, len*breadth);
     }
      return ans;
  }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int area = largestArea(M[0], m);
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(M[i][j]!=0){
                    M[i][j]+= M[i-1][j];
                }
                else{
                    M[i][j]=0;
                }
            }
                area =max(area, largestArea(M[i], m));
        }
        return area;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends