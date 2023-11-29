class Solution {
public:
    int countOf1(int num){
        int count=0;
        while(num!=0){
            if((num&1)==1){
                count++;
            }
            num= num>>1;
        }
        return count;
    }
    bool isPrime(int num){
        if(num<=1) return false;
        if(num==2) return true;
        for(int i=2;i<=sqrt(num); i++){
            if((num%i)==0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        
        for(int i=left; i<=right; i++){
            int numbit1 = countOf1(i);
            if(isPrime(numbit1)){
                ans++;
            }
        }
        return ans;
    }
};