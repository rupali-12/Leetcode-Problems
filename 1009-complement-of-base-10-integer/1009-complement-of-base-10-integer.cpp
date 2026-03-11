class Solution {
public:
    int bitwiseComplement(int n) {
        int mask =0;
        int x = n;
        
        if(n==0){
            return 1;
        }

        // find mask 
        while(n!=0){
            mask = mask<<1 | 1;
            n = n>>1;
        }

        int ans = (~x)&mask;
        return ans;
    }
};