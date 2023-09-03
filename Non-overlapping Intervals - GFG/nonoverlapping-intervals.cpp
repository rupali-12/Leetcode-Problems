//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   static bool comp(const vector<int>& v1, const vector<int>& v2)
    {
        return v1[1] < v2[1];
    }
    int minRemoval(int n, vector<vector<int>> &intervals) {
        // code here
        sort(intervals.begin(), intervals.end(), comp);
        int count=0;   // atleast one element is present 
       vector<vector<int>>ans;
        for(int i=0; i<n; i++){
            if(ans.empty()){
                ans.push_back(intervals[i]);
            }
           else{
               vector<int>&v=ans.back();
                int end= v[1];
            if(end> intervals[i][0]){
                count++;   // count will increase where we need to merge 
            }
            else{
              ans.push_back(intervals[i]);
            }
           }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(N, intervals) << endl;
    }
    return 0;
}
// } Driver Code Ends