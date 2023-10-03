//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
bool solveRec(string text, string pattern, int i, int j){
   // base case 
   if(i<0 && j<0) return true;
   if(i>=0 && j<0) return false;
   if(i<0 && j>=0){
      for(int k=0; k<=j; k++){
         if(pattern[k]!='*') return false;
      }
      return true;
   }

   // case of match 
   if(text[i]==pattern[j] || pattern[j]=='?'){
      return solveRec(text, pattern, i-1, j-1);
      }
      else if(pattern[j]=='*'){
      //   case of replacement of *-> empty string || *-> *ch
      return solveRec(text, pattern, i, j-1) || solveRec(text, pattern, i-1, j);
      }
      else{
         return false;
      }
     return true;
}
bool solveMem(string text, string pattern, int i, int j,  vector<vector<int>>&dp){
   // base case 
   if(i<0 && j<0) return true;
   if(i>=0 && j<0) return false;
   if(i<0 && j>=0){
      for(int k=0; k<=j; k++){
         if(pattern[k]!='*') return false;
      }
      return true;
   }

   // case of match 
   bool ans;
   if(text[i]==pattern[j] || pattern[j]=='?'){
      ans= solveMem(text, pattern, i-1, j-1, dp);
      }
      else if(pattern[j]=='*'){
      //   case of replacement of *-> empty string || *-> *ch
      ans= solveMem(text, pattern, i, j-1, dp) || solveMem(text, pattern, i-1, j, dp);
      }
      else{
         ans= false;
      }
     return dp[i][j]=ans;
}
bool solveTab(string text, string pattern){
      vector<vector<bool>>dp(text.length()+1, vector<bool>(pattern.length()+1, false));
      dp[0][0] = true;
      for(int i=1; i<=text.length(); i++){
         dp[i][0] = false;
      }

      for(int i=1; i<=pattern.length(); i++){
         bool flag=true;
         for(int k= 1; k<=i; k++){
            if(pattern[k-1]!='*'){
               flag= false;
               break;
            }
         }
         dp[0][i]= flag;    // as dp[0][0] =true;so start from i=1 and k=1
      }

      for(int i=1; i<=text.length(); i++){
         for(int j=1; j<=pattern.length(); j++){
            bool ans;
         //  case match 
         if(pattern[j-1]==text[i-1] || pattern[j-1]=='?'){
          ans = dp[i-1][j-1];
         }
         else if(pattern[j-1]=='*'){
           ans = dp[i][j-1] || dp[i-1][j];
         }
         else{
           ans= false;
         }
         dp[i][j]=ans;
           }
      }

      return dp[text.length()][pattern.length()];
}
bool solveTabSpOpt(string text, string pattern){
      vector<bool>prev(pattern.length()+1, false);
      vector<bool>curr(pattern.length()+1, false);
      prev[0] = true;
      // for(int i=1; i<=text.length(); i++){
      //    dp[i][0] = false;
      // } --> it means to set 0th position of every row to 0 precess it in double for loop

      for(int i=1; i<=pattern.length(); i++){
         bool flag=true;
         for(int k= 1; k<=i; k++){
            if(pattern[k-1]!='*'){
               flag= false;
               break;
            }
         }
         prev[i]= flag;    // as dp[0][0] =true;so start from i=1 and k=1
      }

      for(int i=1; i<=text.length(); i++){
         for(int j=1; j<=pattern.length(); j++){
            // curr[0] =false;    not necessary
            bool ans;
         //  case match 
         if(pattern[j-1]==text[i-1] || pattern[j-1]=='?'){
          ans = prev[j-1];
         }
         else if(pattern[j-1]=='*'){
           ans = curr[j-1] || prev[j];
         }
         else{
           ans= false;
         }
         curr[j]=ans;
           }
           prev=curr;
      }

      return prev[pattern.length()];
}
    int wildCard(string pattern,string text){
         // // Approach-1: Recursion 
    // return solveRec(text, pattern, text.length()-1, pattern.length()-1);

   //   // Approach-2: Recursion + Memoization
    //   vector<vector<int>>dp(text.length(), vector<int>(pattern.length(), -1));
    // return solveMem(text, pattern, text.length()-1, pattern.length()-1, dp);

   //  // Approach-3: Tabulation
    // return solveTab(text, pattern);

   //  // Approach-4: Tabulation + space optimization
  return solveTabSpOpt(text, pattern);
        
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends