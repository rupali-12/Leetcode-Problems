class Solution {
public:
    bool isPrime(int num){
        if(num==0 || num==1) return false;

        for(int i=2; i*i<=num; i++){
            if(num%i==0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left; i<=right; i++){
            int setBits = __builtin_popcount(i);
            if(isPrime(setBits)){
                ans++;
            }
        }
        return ans;
    }
};