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
    bool knows(int A, int B, vector<vector<int> >& M, int n){
        // for(int i=0; i<n; i++){
        //     if(M[A][i]==1){
        //         return true;
        //     }
        // }
        if(M[A][B]==1 || M[B][A]==0){
            return true;
        }
        return false;
    }
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>s;
        for(int i=0; i<n; i++){
            s.push(i);
        }
        
        while(s.size()!=1){
            int A = s.top();
            s.pop();
            int B= s.top(); 
            s.pop();
            
            if(knows(A, B, M, n)){
                s.push(B);
            }
            else{
                s.push(A);
            }
        }
        int ansCandidate= s.top();
        for(int i=0; i<n; i++){
            if(M[ansCandidate][i]==1){
                return -1;
            }
        }
        for(int i=0; i<n; i++){
            if(M[i][ansCandidate]==0 && ansCandidate!=i){
                return -1;
            }
        }
        return ansCandidate;
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