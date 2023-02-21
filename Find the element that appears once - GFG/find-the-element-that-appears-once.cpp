//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int A[], int N){
	    //code
	         int s =0, e= N-1;
          int mid =s+(e-s)/2;
 while(s<e){
        if(mid%2==0){
            if(A[mid] == A[mid+1]){
                s =mid+2;
            }
            else{
                e=mid-1;
            }
        }
        else{
              if(A[mid]==A[mid-1]){
                s = mid + 1;;
            }
            else{
                e =mid-2;
            }
        }
    mid =s+(e-s)/2;
        }
        return A[mid];
	    
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends