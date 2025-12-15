class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n= prices.size();
        // Approach-1 Sum 
        long long ans=0;
        long long num=1;   // include first element
        for(int i=1; i<n; i++){
            if(prices[i] == prices[i-1]-1){
                num++;
            }
            else{
                ans+= (num*(num+1))/2;
                num=1;
            }
        }

        // again as if some element not processed then here needs to be done 
        ans+= (num*(num+1))/2;
        return ans;
    }
};