//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int *wt, int *val, int n, int capacity){
        vector<int>prev(capacity+1, 0);
        vector<int>curr(capacity+1, 0);
        // base case 
        for(int w=wt[0]; w<=capacity; w++){
            if(w<=capacity){
                prev[w]=val[0];
            }
            else{
                prev[w]=0;
            }
        }
        
        for(int index=1; index<n; index++){
            for(int w=0; w<=capacity; w++){
                int include=0;
                if(wt[index]<=w){
                    include = val[index] + prev[w-wt[index]];
                }
                int exclude =0 + prev[w];
                curr[w] =max(include, exclude);
            }
            // update prev 
            prev= curr;
        }
        return prev[capacity];
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
    //   using space optimization
    return solve(wt, val, n, W);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends