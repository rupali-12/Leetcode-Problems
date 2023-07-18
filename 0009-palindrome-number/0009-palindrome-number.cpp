class Solution {
public:
    bool isPalindrome(int x) {
        int temp =x;
        long long revNum=0;
        while(temp>0){
            int rem =temp%10;
            revNum = revNum*10 + rem;
            temp/=10;
        }
        if(x==revNum){
            return true;
        }
        return false;
    }
};