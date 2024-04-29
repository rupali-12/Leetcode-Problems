class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int totalxor=nums[0];
        for(int i=1; i<nums.size(); i++){
            totalxor = totalxor^nums[i];
        }
        int ans=0;
        // diff in bit is equivalent to different bits in (totalxor^k)
        totalxor= totalxor^k;
        cout<<totalxor<<endl;
        // // way 1 to count different bit 
        // while(totalxor!=0){
        //     int bit_in_txor = totalxor>>1;
        //     if(bit_in_txor != 1){  // 1 means different bit in totalxor and k 
        //         ans++;
        //     }
        //     totalxor>>=1;
        // }
        
        // way 2 build in function
        ans= __builtin_popcount(totalxor);
        return ans;
    }
};