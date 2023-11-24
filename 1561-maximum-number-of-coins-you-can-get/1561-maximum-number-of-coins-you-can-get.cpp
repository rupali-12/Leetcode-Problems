class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int sum=0;
        sort(piles.begin(), piles.end());
        
        int i=0, j= piles.size()-1;
        while(i<j){
            int alice= piles[j--];
            int me= piles[j--];
            int bob= piles[i++];
            sum+= me;
        }
        return sum;
    }
};