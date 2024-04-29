class Solution {
public:
    int minBitFlips(int start, int goal) {
        int total= start^goal;
        
        int ans=0;
        while(total!=0){
           int bit = total&1;
           if(bit==1){
               ans++;
           }
          total>>=1;
        }
        
        return ans;
    }
};