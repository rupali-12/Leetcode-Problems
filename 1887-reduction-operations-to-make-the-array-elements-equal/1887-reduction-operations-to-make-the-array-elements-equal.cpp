class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        
        // // Approach1: Decreasing order 
        // sort(nums.rbegin(), nums.rend());
        // int count=0, sum=0, prev= 50001;
        // for(int x: nums){
        //     if(x!=prev){
        //         count+= sum;
        //     }
        //      sum++;
        //         prev=x;
        // }
        // return count;
        
        // Approach2: Increasing order 
        sort(nums.begin(),nums.end());
        int n= nums.size(), count=0;
        for(int i=0; i<n-1; i++){
            if(nums[i]!=nums[i+1]){
                count+= n-i-1;
            }
        }
        return count;
    }
};