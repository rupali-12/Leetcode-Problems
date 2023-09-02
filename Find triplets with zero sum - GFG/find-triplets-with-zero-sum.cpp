//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
    // //  Approach-1: Hashing
    // for(int i=0; i<n-1; i++){
    //     unordered_set<int>s;
    //     for(int j=i+1; j<n; j++){
    //         int temp= -1*(arr[i]+arr[j]);
    //         if(s.find(temp)!=s.end()){
    //             return true;
    //         }
    //         else{
    //             s.insert(arr[j]);   // arr[j] bcoz in order to check further values of jth position for each value of ith position 
    //         }
    //     }
    // }
    // return false;
    
    // Approach-2: Sorting
    sort(arr, arr+n);
    for(int i=0; i<n; i++){
        int x= arr[i];
        int l= i+1; 
        int h= n-1;
        while(l<h){
            if(arr[l]+arr[h]+x==0){
                return true;
            }
            else if(x+arr[l]+arr[h]<0){
                l++;
            }
            else{
                h--;
            }
        }
    }
    return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends