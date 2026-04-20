class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int mxAns=0, n=colors.size();

        // // Approach-1: Brute Force
        // for(int i=0; i<n-1; i++){
        //    for(int j=i+1; j<n; j++){
        //       if(colors[i]!=colors[j]){
        //         mxAns = max(mxAns, abs(j-i));
        //       }
        //    }
        // }
        // return mxAns;
       
    //    Approach-2: Optimize O(n)
       int left=0, right=0;
    //    check left idx if any left make max and with n-1
       for(int i=0; i<n; i++){
          if(colors[i]^colors[n-1]){
            left=i;
            break;
          }
       }

    //    check right idx if any right make max and with 0
       for(int i=n-1; i>=0; i--){
          if(colors[i]^colors[0]){
            right=i;
            break;
          }
       }
       mxAns = max(n-1-left, right);   // right-0
       return mxAns;
    }
};