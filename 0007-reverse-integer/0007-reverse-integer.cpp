class Solution {
public:
    int reverse(int x) {
       int num=0;
        while(abs(x)>0){
        int rem= x%10;
          
             if(num< ((-1)*pow(2, 31))/10 || num> ( pow(2, 31)-1)/10){
                return 0;
            }
              num= num*10 + rem;
            x/=10;
        }
        return num;
    }
};



