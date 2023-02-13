class Solution {
public:
    int countOdds(int low, int high) {
        int count=0;
     // int h = ceil(high/2);
        // int l= ceil(low/2);
        // count = h-l;
        for(int i=low; i<=high; i++){
            if(i%2!=0){
                count++;
            }
        }
        return count;
    }
};