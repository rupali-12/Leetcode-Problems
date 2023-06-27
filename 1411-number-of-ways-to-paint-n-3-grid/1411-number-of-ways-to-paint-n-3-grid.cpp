class Solution {
public:
    int numOfWays(int n) {
        long long c3=6, c2=6;
        int mod= 1e9+7;
        
        for(int i=2; i<=n; i++){
             long long temp=c3;
            c3 = (2*c3 +2*c2)%mod;
             c2 = (2*temp +3*c2)%mod; 
        }
        return (c2+c3)%mod;
    }
};