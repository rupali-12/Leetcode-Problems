class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prevbit=n&1;
        n= n>>1;
        while(n!=0){
            if((n&1)==prevbit){
                 return false;
            }
            prevbit=n&1;
            n= n>>1;
        }
        return true;
    }
};