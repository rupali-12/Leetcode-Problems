class Solution {
public:
    int hammingWeight(uint32_t n) {
      int numBits =0;
        while(n!=0){
            if(n&1==1){
                numBits++;
            }
            n= n>>1;
        }
        return numBits;
    }
};