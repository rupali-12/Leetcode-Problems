//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int kadane(vector<int>&arr){
      int maxSoFar=INT_MIN, maxEnd=0;
      for(int i=0; i<arr.size(); i++){
          maxEnd+= arr[i];
          if(maxSoFar < maxEnd){
              maxSoFar = maxEnd;
          }
          if(maxEnd <0){
              maxEnd=0;
          }
      }
      return maxSoFar;
  }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        
        int maxSum=INT_MIN;
        for(int colStart=0; colStart<C; colStart++){
           vector<int>temp(R, 0);
            for(int colEnd=colStart; colEnd<C; colEnd++){
                for(int row= 0; row<R; row++){
                    temp[row]+= M[row][colEnd];
                }
                int currSum =kadane(temp);
                maxSum= max(maxSum, currSum);
            }
        }
        return maxSum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends