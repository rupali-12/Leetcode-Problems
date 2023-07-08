class Solution {
public:
    int countTriplets(vector<int>& arr) {
        // Approach-1>> 
        int n= arr.size();
        int count=0;
       for(int i=0; i<n; i++){
           int val=arr[i];
           for(int k=i+1; k<n; k++){
               val= val^arr[k];
               // if(arr[i]^arr[k]==0){
                 if(val==0){
                   count+= (k-i);
               }
           }
       }
        return count;
    }
};