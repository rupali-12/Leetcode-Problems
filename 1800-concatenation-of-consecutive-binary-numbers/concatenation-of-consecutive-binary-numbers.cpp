class Solution {
public:
int MOD= 1e9+7;
    int concatenatedBinary(int n) {
        long long ans=1;
        for(int i=2; i<=n; i++){
            int lenNew =  32 - __builtin_clz(i);
            ans= ans<<lenNew;   // left shift by length of new number
            ans = (ans + i)%MOD;
        }
        return ans;
    }
};
