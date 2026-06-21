class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans=0, n=costs.size();
        long long currcost=0;
        for(int i=0; i<n; i++){
           currcost+= costs[i];
           if(currcost <= coins) ans++;
        }
        return ans;
    }
};