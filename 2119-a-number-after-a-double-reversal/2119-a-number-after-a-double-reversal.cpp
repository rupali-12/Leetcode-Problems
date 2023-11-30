class Solution {
public:
     int reverseNum(int num){
         int revNum=0;
         while(num!=0){
             int rem = num%10;
             revNum= revNum*10+rem;
             num/=10;
         }
         return revNum;
     }
    bool isSameAfterReversals(int num) {
        int firstRev= reverseNum(num);
        // cout<<firstRev<<" ";
        int secondRev = reverseNum(firstRev);
         // cout<<secondRev<<" ";
        if(num == secondRev){
            return true;
        }
        return false;
    }
};