class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0, j=0, count0=0, ans=0;
        
        while(j<nums.size()){
            if(nums[j]==0){
                count0++;
            }
            // shrink 
            if(count0 > k){
                while(count0 >k){
                    if(nums[i]==0) count0--;
                    i++;
                }
            }
            
            ans= max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};