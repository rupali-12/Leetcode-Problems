class Solution {
public:
    bool canAliceWin(int n) {
        bool isAliceWin= false;
       for(int i=10; i>=0; i--){
        if(n>=i){
            if(i%2==0){
                isAliceWin=true;
            }
            else{
                isAliceWin=false;
            }
            n-=i;
        }
        else break;
       }
       return isAliceWin;
    }
};