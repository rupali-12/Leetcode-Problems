//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here
        // // using map>>>
        // unordered_map<int, int>row, col;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n ;j++){
        //         if(M[i][j]==1){
        //           row[i]++; col[j]++;
        //         }
        //     }
        // }
        
        //   for(int j=0; j<n ;j++){
        //         if(col[j]==n-1 && row[j]==0){
        //             return j;
        //         }
        //     }
        //      return -1;
        
        // Approach-2>>>> 
        stack<int>s;
        for(int i=0; i<n; i++){
            s.push(i);
        }
        
        while(s.size()!=1){
            int A = s.top();
            s.pop();
            int B =s.top();
            s.pop();
            
            // if A knows B 
            if(M[A][B]==1){
                s.push(B);
            }
            // B knows A
            else{
                s.push(A);
            }
        }
      int remCandidate = s.top();
    //   Check all row elements for remCandidate is 0 
      for(int i=0; i<n; i++){
          if(M[remCandidate][i]==1){
             return -1;
          }
      }
    //   Check all column elements for remCandidate is 1 except diagonal element 
      for(int i=0; i<n; i++){
          if(M[i][remCandidate]==0 && i != remCandidate){
              return -1;
          }
      }
      return remCandidate;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends