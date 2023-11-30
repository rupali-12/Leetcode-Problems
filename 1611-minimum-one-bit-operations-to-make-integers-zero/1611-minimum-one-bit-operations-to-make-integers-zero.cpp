typedef long long int ll;
class Solution {
public:
    int minimumOneBitOperations(int n) {
        vector<ll>bitAns(31);
        bitAns[0]=1;
        for(int i=1; i<31; i++){
            bitAns[i]= 2*bitAns[i-1] +1;
        }
        
        int ans=0;
        int plus=1;
        
        for(int i=30; i>=0; i--){
            bool is_ith_bit_set = ((1<<i)&n)!=0;   // means bit 1 h 
            if(is_ith_bit_set==0) continue;   // means bit 0 h
            
            if(plus){
                ans+= bitAns[i];
            }
            else ans-= bitAns[i];
           plus= !plus;
        }
        return ans;
    }
};