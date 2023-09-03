//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          // code here  
        //  store x and b in map 
        unordered_map<char, int>mp;
        for(int i=0; i<n; i++){
            mp[x[i]]= b[i];
        }
        
        int sum=0, maxSum=INT_MIN;
        string temp="", ans="";
        for(int i=0; i<w.length(); i++){
                temp+= w[i];
            if(mp.find(w[i])!=mp.end()){
                // if find then add redefined ascii value 
                sum+= mp[w[i]];
            }
            else{
                // use actual ascii 
                sum+= w[i];
            }
           if(sum>maxSum){
               maxSum= sum;
            ans=temp;
           }
            if(sum<0){
                sum=0;
                temp="";
            }
        }
        return ans;
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends