class Solution {
public:
    int hammingWeight(uint32_t n) {
       int num1bit=0;
        while(n!=0){
            if(n&1==1){
                num1bit++;
            }
            n= n>>1;
        }
        return num1bit;
    }
};