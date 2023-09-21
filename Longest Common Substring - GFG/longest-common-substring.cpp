//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
        int solveRec(string S1, string S2, int i , int j , int cnt){
        if(i==S1.length() || j==S2.length()) return cnt;
        
        //match case
        if(S1[i]==S2[j]){
            cnt=solveRec(S1, S2,i+1,j+1,cnt+1);
        }
        
        //for not match case 
        cnt=max(cnt, max(solveRec(S1, S2,i+1,j,0), solveRec(S1, S2,i,j+1,0))) ;
        return cnt;
    } 
     int solveTab(string S1, string S2){
        vector<vector<int>>dp(S1.length()+1, vector<int>(S2.length()+1, 0));
         int ans=0;
         for(int i=1; i<=S1.length(); i++){
             for(int j=1; j<=S2.length(); j++){
                 if(S1[i-1]==S2[j-1]){    // as 1-based indexing is used
                     dp[i][j]= 1+ dp[i-1][j-1];
                 }
                 else{
                     dp[i][j]=0;
                 }
                 ans= max(ans, dp[i][j]);
             }
         }
         return ans;
    } 
     int solveTabSpOpt(string S1, string S2){
         vector<int>prev(S2.length()+1, 0);
         vector<int>curr(S2.length()+1, 0);
         int ans=0;
         for(int i=1; i<=S1.length(); i++){
             for(int j=1; j<=S2.length(); j++){
                 if(S1[i-1]==S2[j-1]){    // as 1-based indexing is used
                     curr[j]= 1+ prev[j-1];
                 }
                 else{
                     curr[j]=0;
                 }
                 ans= max(ans, curr[j]);
             }
             prev=curr;
         }
         return ans;
    } 
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
         // // Approach-1: Recursion
        // // (i, j, count)
        // return solveRec(S1, S2, 0, 0, 0);
        
         //  // Approach-2: (Tabulation)
        // return solveTab(S1, S2);
        
         // Approach-3: (Tabulation + space optimization)
        return solveTabSpOpt(S1, S2);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends