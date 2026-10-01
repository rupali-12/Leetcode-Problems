class Solution {
public:
    bool canFinish(vector<int>& piles, int k, int h){
        long long hours =0;
        for(auto pile: piles){
            hours += ceil(pile+k-1)/k;
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left =1, right=1;

        // find max value 
        for(auto pile: piles){
            right = max(right, pile);
        }

        while(left<right){
          int mid = left +(right-left)/2;
          if(canFinish(piles, mid, h)){
            right = mid;
          }
          else{
            left= mid+1;
          }
        }
        return left;
    }
};