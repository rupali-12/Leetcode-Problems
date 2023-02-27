//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
    //   int start=0;
    //   int balance=0;
    //   int deficiet=0;
    //   for(int i=start; i<n; i++){
    //       balance= balance + (p[i].petrol- p[i].distance);
    //       if(balance<0){
    //           deficiet+= balance;
    //           start= i+1;
    //           balance=0;
    //       }
    //   }
    //   if(deficiet+balance >=0){
    //       return start;
    //   }
    //   else{
    //       return -1;
    //   }
    
    
    // 2nd approach usng queue>>>>
    int start=0;
    int end= 1;
    int balance=p[start].petrol - p[start].distance;
 while(start!=end || balance<0){
     while(start!=end && balance<0){
         balance-= p[start].petrol - p[start].distance;
         start =(start+1)%n;
         
         if(start==0){
             return -1;
         }
     }
     balance+= p[end].petrol - p[end].distance;
      end = (end+1)%n;
    
 }
    return start;  
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
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends