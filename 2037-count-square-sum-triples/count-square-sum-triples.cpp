class Solution {
public:
    int countTriples(int n) {
        int ans=0;
        for(int a=1; a<=n; a++){
            for(int b=a+1; b<=n; b++){
                int csqr = a*a + b*b;
                int c= sqrt(csqr);
                if(c<=n && c*c==csqr){
                    ans+=2;    // as (a, b, c) and (b,a,c) same
                }
            }
        }
        return ans;
    }
};

