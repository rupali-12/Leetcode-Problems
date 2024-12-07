class Solution {
public:
    
    bool isPossible(vector<int>&nums, int maxOperations, int mid){
        int totalOp=0;
        for(auto num: nums){
            int op= num/mid;
            
            if(num%mid ==0){
                op-=1;
            }
            totalOp+=op;
        }
        return totalOp <= maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l= 1;
        int r= *max_element(nums.begin(), nums.end());
        int ans=r;
        
        while(l<=r){
            int mid= l +(r-l)/2;
            if(isPossible(nums, maxOperations, mid)){
                ans= mid;
                r= mid-1;
            }
            else{
                l= mid+1;
            }
        }
        return ans;
    }
};