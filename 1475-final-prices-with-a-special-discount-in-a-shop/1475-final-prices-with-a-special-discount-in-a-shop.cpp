class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n= prices.size();
 stack<int>s;
   vector<int>ans(n);
   s.push(0);
   for(int i=n-1; i>=0; i--){
     while (s.top() > prices[i]) {
       s.pop();
     }
         ans[i]= prices[i]- s.top();
         s.push(prices[i]);
   }
   return ans;
    }
};