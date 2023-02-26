//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    // //   Approach-1> .
    //     deque<int>dq;
    //      vector<long long>ans;
    //     for(int i=0; i<K; i++){
    //         if(A[i]<0){
    //             dq.push_back(i);
    //         }
    //     }
        
    //     // store ans for first window
    //     if(dq.size()>0){
    //       ans.push_back(A[dq.front()]);
    //     }
    //     else{
    //       ans.push_back(0);    
    //     }
        
    //     // Process further windows 
    //     for(int i=K; i<N; i++){
    //         if(!dq.empty() && (i-dq.front())>=K){
    //           dq.pop_front();
    //         }
            
    //         // addition of next index
    //         if(A[i]<0){
    //             dq.push_back(i);
    //         }
            
    //         // store ans>>>>
    //          if(dq.size()>0){
    //       ans.push_back(A[dq.front()]);
    //     }
    //     else{
    //       ans.push_back(0);    
    //     }
            
    //     }
    //     return ans;
    
    
//     // >>Approach-2>>>>  only 10055 test passed
//   vector<long long int>ans;
//   for(int i=0; i<N-K+1; i++){
//       int j=0, l=i, flag=0;
//       while(j<K){
//           if(A[l]<0){
//               flag=1;
//               break;
//           }
//           l++; j++;
//       }   
//       if(flag==1){
//           ans.push_back(A[l]);
//       }
//       else{
//           ans.push_back(0);
//       }
//   }
//     return ans;
    
    
    // Approach-3> optimized 
    int firstNegIndex=0;
    int firstNegElement;
    vector<long long int>ans;
   for(int i=K-1; i<N; i++){
       while((firstNegIndex<i) && (firstNegIndex<=i-K || A[firstNegIndex]>=0)){
           firstNegIndex++;
       }
       if(A[firstNegIndex]<0){
           firstNegElement= A[firstNegIndex];
       }
       else{
           firstNegElement=0;
       }
       ans.push_back(firstNegElement);
   }
   return ans;
 }



 