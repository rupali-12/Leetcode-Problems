class Solution {
public:
    int numberOfWays(string corridor) {
        int n= corridor.length();
        int ans=1;
        int totalSeats=0;
        const int mod = 1e9+7;
        for(int i=0; i<n; i++){
            if(corridor[i]=='S'){
                totalSeats++;
            }
        }

        // if totalSeats is odd 
        if(totalSeats==0 || totalSeats%2!=0) return 0;

        int CurrSeatCount =0, plants=0;
      for(auto c: corridor){
        if(c=='S'){
           CurrSeatCount++;
           if(CurrSeatCount>2 && CurrSeatCount%2==1){
            ans = (1LL*ans*(plants+1))%mod;
            plants=0;
           }
        }
        else{
            // not all P matter only after seat pairs matter
            if(CurrSeatCount>=2 && CurrSeatCount%2==0){
                plants++;
            }
        }
      }
        return ans;
    }
};