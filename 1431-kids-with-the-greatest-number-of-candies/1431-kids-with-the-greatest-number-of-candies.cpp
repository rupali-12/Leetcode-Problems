class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // find max element from candies array
        int n =candies.size();
        int mx=0;
        for(int i=0; i<n; i++){
            if(candies[i]>mx){
                mx =candies[i];
            }
        }
        vector<bool>ans(n);
        for(int i=0; i<n; i++){
            int val =candies[i] + extraCandies;
            if(val>=mx){
                ans[i]= true;
            }
            else{
                ans[i]=false;
            }
        }
        return ans;
    }
};