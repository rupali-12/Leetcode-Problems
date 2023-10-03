//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  vector<int>nextSmaller(int *mat, int n){
        stack<int>s;
        s.push(-1);
        vector<int>ans(n);
        for(int i=n-1; i>=0; i--){
             while(s.top()!=-1 && mat[s.top()]>=mat[i]){
              s.pop();
          }
            ans[i] = s.top();
            s.push(i);
        }
      return ans;
    }
     vector<int>prevSmaller(int *mat, int n){
        stack<int>s;
        s.push(-1);
        vector<int>ans(n);
        for(int i=0; i<n; i++){
             while(s.top()!=-1 && mat[s.top()]>=mat[i]){
              s.pop();
          }
            ans[i] = s.top();
            s.push(i);
        }
      return ans;
    }
    int largestArea(int *mat, int n){
        int maxArea =INT_MIN;
        vector<int>next = nextSmaller(mat,n);
        vector<int>prev = prevSmaller(mat,n);
        
        for(int i=0; i<n; i++){
            if(next[i]==-1){     // to avoid negative value of width
                next[i]= n;
            }
            int width = next[i]- prev[i]-1;
            int area = mat[i]*width;
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
    //     // Way-1: 
    //   int histogram[m]={0};
    //     int maxRec =INT_MIN;
    //     for(int i=0; i<n; i++){
    //         // To create histogram array 
    //         for(int j=0; j<m; j++){
    //             if(M[i][j]==1){
    //               histogram[j]++;
    //             }
    //             else{
    //                  histogram[j]=0;
    //             }
    //         }
    //         maxRec = max(maxRec, largestArea(histogram, m));
    //     }
    //     return maxRec;
    
    // Way-2: 
    int maxRec = largestArea(M[0], m);
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            if(M[i][j]==1){
                M[i][j]+= M[i-1][j];
            }
            else{
                M[i][j]=0;
            }
        }
        maxRec = max(maxRec, largestArea(M[i], m));
    }
    return maxRec;

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