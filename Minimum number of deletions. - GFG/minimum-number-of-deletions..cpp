//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends

int solveTab(string str, string revStr, int n){
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
  
   for(int i=n-1; i>=0; i--){
       for(int j=n-1; j>=0; j--){
           if(str[i]==revStr[j]){
               dp[i][j] = 1 + dp[i+1][j+1];
           }
           else{
               dp[i][j]= max(dp[i+1][j], dp[i][j+1]);
           }
       }
   }
   return dp[0][0];
}
int minDeletions(string str, int n) { 
    //complete the function here 
    string revStr=str;
    reverse(revStr.begin(), revStr.end());
    int lengthOfPalindrome= solveTab(str, revStr, n);
    int minDel=n-lengthOfPalindrome;
    return minDel;
} 