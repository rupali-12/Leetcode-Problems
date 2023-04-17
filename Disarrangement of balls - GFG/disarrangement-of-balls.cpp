//{ Driver Code Starts
// Initial function Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define mod 1000000007
class Solution{
public:
long long solveSpOpt(int n){
    // prev1  prev2  curr;
    long long int prev1=0, prev2= 1, curr;
    for(int i=3; i<=n; i++){
        curr =((i-1)*(prev1+prev2)%mod);
        prev1 =prev2;
        prev2 =curr;
    }
  return prev2;
}
    long int disarrange(int N){
        // code here
         long long int ans =solveSpOpt(N);
    return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.disarrange(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends