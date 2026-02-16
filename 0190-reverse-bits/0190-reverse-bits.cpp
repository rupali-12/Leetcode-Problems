class Solution {
public:
    int reverseBits(int n) {
        // uint32_t result =0;
        // for(int i=0; i<32; i++){
        //     int lsb = n & 1;
        //     int revLsb = lsb << (31-i);
        //     result = revLsb | result;
        //     n= n>>1;
        // }
        // return result;

        uint32_t result =0;
        for(int i=0; i<32; i++){
            int lsb = n & 1;
            result = result<<1;
            result = result | lsb;
            n= n>>1;
        }
        return result;
    }
};