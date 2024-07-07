class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles, rem=0;
        while((numBottles+rem)>=numExchange){
            int newBottles = (numBottles+rem)/numExchange;
            rem = (numBottles+rem)%numExchange;
            ans+= newBottles;
            numBottles =newBottles;
        }
        return ans;
    }
};