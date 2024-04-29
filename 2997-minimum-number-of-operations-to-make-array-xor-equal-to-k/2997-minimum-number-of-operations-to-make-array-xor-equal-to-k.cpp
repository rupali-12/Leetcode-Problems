class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int totalxor=nums[0];
        for(int i=1; i<nums.size(); i++){
            totalxor = totalxor^nums[i];
        }
        int ans=0;
        
        // way 1 to count different bit 
        while(totalxor!=0 || k!=0){
            int bit_in_txor = totalxor&1;
            int bit_in_k= k&1;
            if(bit_in_txor != bit_in_k){  // 1 means different bit in totalxor and k 
                ans++;
            }
            totalxor>>=1;
            k >>=1;
        }
        
        // // way 2 build in function
        // // diff in bit is equivalent to different bits in (totalxor^k)
        // totalxor= totalxor^k;
        // ans= __builtin_popcount(totalxor);
        return ans;
    }
};