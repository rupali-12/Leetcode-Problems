class Solution {
public:
int solveRec(int i, vector<int>&nums, int rem){
    if(i>=nums.size()){
     if(rem%3==0){
        return 0;
     }
     return INT_MIN;
    }

    int take = nums[i] + solveRec(i+1, nums, (nums[i]+rem)%3);
    int skip = solveRec(i+1, nums, rem);
    return max(take, skip);
}

int solveMem(int i, vector<int>&nums, int rem, vector<vector<int>>&dp){
    if(i>=nums.size()){
     if(rem%3==0){
        return 0;
     }
     return INT_MIN;
    }

    if(dp[i][rem]!=-1){
        return dp[i][rem];
    }

    int take = nums[i] + solveMem(i+1, nums, (nums[i]+rem)%3, dp);
    int skip = solveMem(i+1, nums, rem, dp);
    return dp[i][rem] = max(take, skip);
}
    int maxSumDivThree(vector<int>& nums) {

    //     // Approach1: 
    //     int sum=0;
    //     // contain elements gives remainder as 1
    //     vector<int>remain1;
    //     // contain elements gives remainder as 2
    //     vector<int>remain2;

    //     for(int num: nums){
    //         sum+=num;
    //         if(num%3 ==1){
    //             remain1.push_back(num);
    //         }
    //         else if(num%3 ==2){
    //             remain2.push_back(num);
    //         }
    //     }

    //    if(sum%3 ==0) return sum;
    //    sort(remain1.begin(), remain1.end());
    //    sort(remain2.begin(), remain2.end());

    //     int result=0;
    //     int remainder = sum%3;  // either 1 or 2
    //     if(remainder ==1){
    //       int remove1 = remain1.size() >=1 ? remain1[0] : INT_MAX;
    //       int remove2 = remain2.size() >=2 ? (remain2[0] + remain2[1]) : INT_MAX;
    //       result = max(result, sum - min(remove1, remove2)); 
    //     }
    //     else{
    //       int remove1 = remain1.size() >=2 ? remain1[0] + remain1[1] : INT_MAX;
    //       int remove2 = remain2.size() >=1 ? remain2[0] : INT_MAX;
    //       result = max(result, sum - min(remove1, remove2));         
    //     }
    //     return result;

    // // Approach2: DP
    // int n= nums.size();
    // return solveRec(0, nums, 0);  // idx, nums, rem

    // Approach3: DP + Memoization
    int n= nums.size();
    vector<vector<int>>dp(n, vector<int>(3, -1));
     return solveMem(0, nums, 0, dp);  // idx, nums, rem, dp
    }
};