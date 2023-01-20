class Solution {
public:
    int reverse(int x) {
        int revNum=0;
        while(x!=0){
            int rem= x%10;
            if((INT_MAX/10 < revNum) || (INT_MIN/10 > revNum)){
               return 0;
            }
            revNum= (revNum*10)+rem;
            x/=10;
        }
            return revNum;
    }
};