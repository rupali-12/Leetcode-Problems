class Solution {
public:
    int maxProduct(int n) {
        int ans=1, firstmx=-1, secondmx=-1;
        while(n>0){
            int tmp = n%10;
            if(tmp > firstmx){
                secondmx =firstmx;
                firstmx = tmp;
            }
            else if(tmp>secondmx){
                secondmx = tmp;
            }
            n/=10;
        }
        return firstmx*secondmx;
    }
};