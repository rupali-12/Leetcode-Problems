class Solution {
public:
    bool isPrime[1000];
    void sieve(){
        fill(isPrime, isPrime+1000, true);
        isPrime[0]=false;
        isPrime[1]= false;
        
        for(int i=2; i*i<1000; i++){
            if(isPrime[i]){
                for(int j=i*i; j<1000; j+=i){
                    isPrime[j]=false;
                }
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        int n= nums.size();
        
        sieve();    // populate isPrime array
        
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]) continue;
            
            // case when decrease nums[i] atleast less than nums[i]
            for(int p=2; p<nums[i]; p++){
                if(!isPrime[p]) continue;
                
                if(nums[i] - p < nums[i+1]){
                    nums[i]-= p;
                    break;
                }
            }
            
            if(nums[i]>= nums[i+1]){
                return false;
            }
        }
        return true;
    }
};