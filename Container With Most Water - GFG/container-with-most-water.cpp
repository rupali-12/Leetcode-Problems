//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long arr[], int len)
{
    // Your code goes here
    if(len==0){
        return 0;
    }
    long long left=0, right= len-1, maxarea= INT_MIN;
    while(left<=right){
        long long  area= min(arr[left], arr[right])*(right-left);
        maxarea= max(area, maxarea);
        if(arr[left]<arr[right]){
            left++;
        }
        else{
            right--;
        }
    }
    return maxarea;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends