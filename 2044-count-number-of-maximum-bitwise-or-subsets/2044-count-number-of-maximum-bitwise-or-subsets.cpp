class Solution {
public:
    int solveRec(int idx, int currOr, vector<int>nums, int &maxOr){
        if(idx==nums.size()){
            
            if(currOr==maxOr) return 1;
            else return 0;
        }
        
        // Take 
        int takeCount= solveRec(idx+1, currOr | nums[idx], nums, maxOr);
        
         // Not Take 
        int notTakeCount= solveRec(idx+1, currOr, nums, maxOr);
        
        return takeCount + notTakeCount;
    }
    int countMaxOrSubsets(vector<int>& nums) {
         int maxOr =0;
        for(auto n: nums){
            maxOr= maxOr | n;
        }
        int currOr=0;
        
        // Approach-1: Recursion 
        return solveRec(0, currOr, nums, maxOr);
    }
};