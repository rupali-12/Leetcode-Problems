class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int count=0;
        
        //  // Approach-1: 
        // for(int i=0; i<n; i++){
        //     int val= arr[i];
        //     for(int k=i+1; k<n; k++){
        //         val= val^arr[k];
        //         if(val==0){
        //             count+= (k-i);
        //         }
        //     }
        // }
        // return count;
        
        // Approach-2: Using Prefix sum 
        vector<int>prefix(n+1, 0);
        
        for(int i=1; i<=n; i++){
            prefix[i] = prefix[i-1]^arr[i-1];
        }
        
        for(int i=0; i<=n; i++){
            for(int k=i+1; k<=n; k++){
                if(prefix[i]==prefix[k]){
                    count+= (k-i-1);
                }
            }
        }
        return count;
    }
};