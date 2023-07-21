class Solution {
public:
    // Give TLE for large inputs 
// bool isPrime(int n){
//     if(n==0 || n==1){
//         return false;
//     }
    
//         for(int i=2; i<=n/2; i++){
//             if(n%i==0){
//                 return false;
//             }
//         }
//         return true;
// }
//     int countPrimes(int n) {
//         int count=0;
//       for(int i=1; i<n; i++){
//           if(isPrime(i)){
//               count++;
//           }
//       }
//         return count;
//     }
    
 // Approach-2>> sieve method 
    int countPrimes(int n) {
        int count=0;
        if(n==0 || n==1){
            return 0;
        }
      vector<bool>isPrime(n+1,true);
        isPrime[0]=isPrime[1]=false;
        for(int i=2; i<n; i++){
            int j=1;
            if(isPrime[i]){
                count++;
                 while(i*j <n){
                isPrime[i*j]=false;
                j++;
            }
            }
        }
        return count;
    }
};