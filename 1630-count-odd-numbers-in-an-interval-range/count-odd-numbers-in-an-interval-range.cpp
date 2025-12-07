class Solution {
public:
    int countOdds(int low, int high) {
        // odds from low to high=odds up to high−odds up to (low - 1)
        // for 0 to high = (high+1)/2; 
        // for 0 to low-1 = ((low-1)+1)/2; = low/2; 

        int count = (high+1)/2 - low/2;
        return count;
    }
};