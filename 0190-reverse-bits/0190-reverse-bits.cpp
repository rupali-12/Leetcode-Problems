class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result=0;
        for(int i=0; i<32; i++){
            int lsb= n & 1;
            int revLsb = lsb << (31-i);    // (32-i-1)
            result = revLsb | result;
            n= n>>1;
        }
        return result;
    }
};