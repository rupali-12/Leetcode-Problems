//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool binSearch(int *arr, int element, int low, int high){
	    if(low>high){
	        return false;
	    }
	    int mid= low+(high-low)/2;
	    if(arr[mid]==element){
	           return true;
	       }
	       else if(arr[mid]<element){
	         return binSearch(arr, element, mid+1, high);
	       }
	       else{
	        return  binSearch(arr, element, low, mid-1);
	       }
	
	}
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	   //// Approach-1: Naive 
	   //for(int i=0; i<n; i++){
	   //    for(int j=i+1; j<n; j++){
	   //        if(arr[i]+arr[j]==x){
	   //            return true;
	   //        }
	   //    }
	   //}
	   //return false;
	   
	   ////Approach-2: Two pointer approach 
	   //sort(arr, arr+n);
	   //int i=0, j=n-1;
	   //while(i<j){
	   //    if(arr[i]+arr[j]==x){
	   //        return true;
	   //    }
	   //    else if(arr[i]+arr[j]<x){
	   //        i++;
	   //    }
	   //    else{
	   //        j--;
	   //    }
	   //}
	   //return false;
	   
// 	   //Approach-3: Binary search 
// 	      sort(arr, arr+n);
// 	  for(int i=0; i<n-1; i++){
// 	      int temp= x-arr[i];
// 	      if(binSearch(arr, temp, i+1, n-1)){
// 	          return true;
// 	      }
// 	  }
// 	  return false;

// Aproach-4: Hashing 
            unordered_set<int>s;
       for(int i=0; i<n; i++){
           int temp= x-arr[i];
         if(s.find(temp)!=s.end()){
               return true;
           }
           else{
               s.insert(arr[i]);
           }
       }
       return false;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}

// } Driver Code Ends