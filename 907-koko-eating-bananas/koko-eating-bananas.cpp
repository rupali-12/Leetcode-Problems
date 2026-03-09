class Solution {
public:
    bool canFinish(vector<int>& piles, int speed, int h){
        long long hours =0;
        for(auto pile:piles){
           hours+= ceil((pile+speed-1)/speed);
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left =1, right=1;

        // find max value for right 
        for(auto pile: piles){
            right =max(right, pile);
        }

        // check if we can finish 
        while(left<=right){
            int mid =left + (right-left)/2;
            if(canFinish(piles, mid, h)){
                right = mid-1;
            }
            else{
                left =mid+1;
            }
        }
        return left;
    }
};