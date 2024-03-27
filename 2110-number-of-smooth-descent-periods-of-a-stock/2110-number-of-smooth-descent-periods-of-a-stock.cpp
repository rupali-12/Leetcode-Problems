class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n= prices.size();
        
        // // way-1:
        // long long ans=0, num=1;
        // for(int i=1; i<n; i++){
        //     if(prices[i]==prices[i-1]-1){
        //         num++;
        //     }
        //     else{
        //         ans+= (num*(num+1))/2;
        //         num=1;
        //     }
        // }
        // ans+=  (num*(num+1))/2;
        // return ans;
        
        // Way-2: 
        long long ans=0;
        int i=0, j=0;
        for(int j=1; j<n; j++){
            while(j<n && prices[j]==prices[j-1]-1){
                ans+= j-i;
                j++;
            }
            i=j;
        }
        return ans+n;
    }
};