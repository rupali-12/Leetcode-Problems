class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minsofar=prices[0], maxProfit =0;
        for(int i=0; i<prices.size(); i++){
            minsofar =min(minsofar, prices[i]);
            int profit = prices[i]-minsofar;
            maxProfit = max(profit, maxProfit);
        }
        return maxProfit;
    }
};