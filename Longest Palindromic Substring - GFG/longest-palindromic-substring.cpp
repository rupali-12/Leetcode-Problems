//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    string longestPalindrome(string S){
        // code here 
        int n= S.length();
  string ans="";
  for(int i=0; i<n; i++){
      string temp="";
      string temp2="";
      for(int j=i; j<n; j++){
          temp+=S[j];
          temp2= S[j]+temp2;
          if(temp==temp2 && ans.length()<temp.length()){
              ans=temp;
          }
      }
  }
  return ans;
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends