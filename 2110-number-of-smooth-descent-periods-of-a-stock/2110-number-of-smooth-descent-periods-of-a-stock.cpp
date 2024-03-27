class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n= prices.size();
        long long ans=0, num=1;
        for(int i=1; i<n; i++){
            if(prices[i]==prices[i-1]-1){
                num++;
            }
            else{
                ans+= (num*(num+1))/2;
                num=1;
            }
        }
        ans+=  (num*(num+1))/2;
        return ans;
    }
};