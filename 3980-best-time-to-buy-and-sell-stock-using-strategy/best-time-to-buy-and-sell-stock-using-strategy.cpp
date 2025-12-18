class Solution {
public:
typedef long long ll;
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n= prices.size();
        ll actualProfit=0;
        vector<ll>profit(n);

        for(int i=0; i<n; i++){
            profit[i] = prices[i]*strategy[i];
            actualProfit+= profit[i];
        }
       
       ll originalWindowProfit = 0;
       ll modifiedWindowProfit = 0;
       ll maxGain = 0;
       int i=0, j=0;

       while(j<n){
        originalWindowProfit+= profit[j];

        // second half of window contribute to modifiedWindowProfit
        if(j-i+1 > k/2){
            modifiedWindowProfit+= prices[j];
        }

        // shrink 
        if(j-i+1 >k){
            originalWindowProfit-= profit[i];
            modifiedWindowProfit-= prices[i+k/2];
            i++;
        }
        
        // calculate once reach window size 
        if(j-i+1 == k){
            maxGain = max(maxGain, (modifiedWindowProfit-originalWindowProfit));
        }
        j++;
       }
      return actualProfit+maxGain;
    }
};