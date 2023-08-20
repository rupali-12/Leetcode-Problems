class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
       int n= arr.size();
        vector<long>next_smaller(n);
        vector<long>prev_smaller(n);
        stack<pair<long, long>>s1, s2;
      // next smaller contribution
        for(int i=0; i<n; i++){
            int count=1;
            while(!s1.empty() && arr[i]<= s1.top().first){
                count+= s1.top().second;
                s1.pop();
            }
            s1.push({arr[i], count});
            next_smaller[i]= count;
        }
        
        // prev smaller contribution 
        for(int i=n-1; i>=0; i--){
            int count=1;
            while(!s2.empty() && arr[i]< s2.top().first){
                count+= s2.top().second;
                s2.pop();
            }
            s2.push({arr[i], count});
            prev_smaller[i]=count;
        }
        
        long long sum=0;
        long long mod=  1e9+7;
        for(int i=0; i<n; i++){
            sum+= arr[i]*next_smaller[i]*prev_smaller[i];
            sum%=mod;
        }
    return sum;
}
};