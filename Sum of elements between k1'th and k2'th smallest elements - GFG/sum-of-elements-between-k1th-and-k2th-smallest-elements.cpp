//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
     long long kthSmallest(long long A[], long long k, priority_queue<long long, vector<long long>, greater<long long>>mini){
         long long  ans;
         long long i=1;
         while(i<=k){
             ans= mini.top();
             mini.pop();
             i++;
         }
         return ans;
     }
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        priority_queue<long long, vector<long long>, greater<long long>>mini;
        for(int i=0; i<N; i++){
            mini.push(A[i]);
        }
        
       long long first = kthSmallest(A, K1, mini);
       long long second = kthSmallest(A, K2, mini);

       
       long long sum=0;
       for(int i=0; i<N; i++){
           if(A[i]>first && A[i]<second){
               sum+= A[i];
           }
       }
       return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends