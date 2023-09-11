//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
const int mod= 1003;
   int solveRec(string &s, int i, int j, bool isTrue){
       if(i>j) return 0;
    //  if isTrue==false adn we search for s[i]=F so it will return true 
    if(i==j){    // case of 1 character 
      if(isTrue==true){
           return s[i] =='T';   //compare
       }
       else{  // isTrue= false
           return s[i]=='F';
       }
    }
    int ans=0;
    for(int k=i+1; k<=j; k+=2){
        int lt = solveRec(s, i, k-1, true);
        int lf = solveRec(s, i, k-1, false);
        int rt = solveRec(s, k+1, j, true);
        int rf = solveRec(s, k+1, j, false);
        
        int ltrt =( lt*rt);
        int lfrf= (lf*rf);
        int ltrf= lt*rf;
        int lfrt = lf*rt;
        
        if(s[k]=='&'){
            if(isTrue==true){
                ans = ans + ltrt;
            }
            else{
                ans= ans + ltrf + lfrt + lfrf;
            }
        }
        else if(s[k]=='|'){
             if(isTrue==true){
                ans = ans + ltrt + ltrf + lfrt;
            }
            else{
                ans= ans + lfrf;
            }
        }
        else if(s[k]=='^'){
             if(isTrue==true){
                ans = ans + ltrf + lfrt;
            }
            else{
                ans= ans + ltrt + lfrf;
            }
        }
    }
    return ans;
   }
   
//   Memoization 
   int solveMem(string &s, int i, int j, bool isTrue, vector<vector<vector<int>>>&dp){
       if(i>j) return 0;
    //  if isTrue==false adn we search for s[i]=F so it will return true 
    if(i==j){    // case of 1 character 
      if(isTrue==true){
           return s[i] =='T';   //compare
       }
       else{  // isTrue= false
           return s[i]=='F';
       }
    }
    
    if(dp[i][j][isTrue]!=-1){
        return dp[i][j][isTrue];
    }
    int ans=0;
    // for(int k=i+1; k<=j; k+=2){
    for(int k=i+1; k<=j-1; k+=2){
        int lt = solveMem(s, i, k-1, 1, dp);
        int lf = solveMem(s, i, k-1, 0, dp);
        int rt = solveMem(s, k+1, j, 1, dp);
        int rf = solveMem(s, k+1, j, 0, dp);
        
        int ltrt =( lt*rt)%mod;
        int lfrf= (lf*rf)%mod;
        int ltrf=( lt*rf)%mod;
        int lfrt = (lf*rt)%mod;
        
        if(s[k]=='&'){
            if(isTrue==true){
                ans = (ans + ltrt)%mod;
            }
            else{
                ans= (ans + ltrf + lfrt + lfrf)%mod;
            }
        }
        else if(s[k]=='|'){
             if(isTrue==true){
                ans = (ans + ltrt + ltrf + lfrt)%mod;
            }
            else{
                ans= (ans + lfrf)%mod;
            }
        }
        else if(s[k]=='^'){
             if(isTrue==true){
                ans = (ans + ltrf + lfrt)%mod;
            }
            else{
                ans= (ans + ltrt + lfrf)%mod;
            }
        }
    }
    return dp[i][j][isTrue]= ans;
   }
    int countWays(int n, string s){
        // code here
        int i=0, j= n-1;
        bool isTrue= true;
        
        // // Approach-1: Recursion 
        // return solveRec(s, i, j, isTrue);
        
        
        // // Approach-2: Recursion  +Memoization 
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return solveMem(s, i, j, isTrue, dp);
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends