//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPossible(int time[], int n, int m, int mid){
    int currSum=0, chapCount=1;
    for(int i=0; i<n; i++){
        if(currSum+time[i] <= mid){
            currSum+= time[i];
        }
        else{
            chapCount++;
            if(chapCount>m || time[i]>mid){
                return false;
            }
            currSum= time[i];
        }
    }
    return true;
}
    int findPages(int time[], int n, int m) 
    {
    //     //code here
    //     if(m>n){
    //         return -1;
    //     }
    //      int s=0;
    // int sum=0;
    // for(int i=0; i<n; i++){
    //     sum+=time[i];
    // }
    // int e=sum;
    // int ans=-1;
    // int mid =s+(e-s)/2;
    // while(s<=e){
    //     if(isPossible(time, n, m, mid)){
    //         ans=mid;
    //         e= mid-1;
    //     }
    //     else{
    //         s=mid+1;
    //     }
    //     mid =s+(e-s)/2;
    // }
    // return ans;
    
    
    // Approach-2>> 
    if(m>n){
        return -1;
    }
    long long sum =0;
    for(int i=0; i<n; i++){
        sum+=time[i];
    }
     long res=INT_MIN;   // find max
    for(int i=0; i<n; i++){
        if(time[i]>res){
            res= time[i];
        }
    }
    long long s=res, e= sum, ans=-1;

    while(s<=e){
     long long currentTime=0, daysCount=1;
    long long mid= s+(e-s)/2;
        for(int i=0; i<n; i++){
            currentTime+=time[i];
            if(currentTime> mid){
                daysCount++;
                currentTime = time[i];
            }
        }
        if(daysCount<=m){
            ans= mid;
            e=mid-1;
        }
        else{
            s= mid+1;
        }
    }
    return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends