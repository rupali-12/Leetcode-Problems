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
    bool knows(vector<vector<int> >& M, int can, int per){
        if(M[can][per]==1){
            return true;
        }
        return false;
    }
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        int  c=0;
        for(int i=0; i<n; i++){
            if(knows(M, c, i)){
                c=i;
            }
        }
        
        // check if candidate knows anyone or not 
        for(int i=0; i<n; i++){
            if(i==c) continue;
            // if c knows everyone but there exist an i which does not know c then return -1;
            if(knows(M, c,i) || (!knows(M, i, c))){
                return -1;
            }
        }
        return c;
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