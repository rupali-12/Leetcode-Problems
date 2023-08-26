class Solution {
public:
   int solve(vector< int>&nums, int start, int end){
    int prev2=0,prev1 = nums[start];
    // prev2  prev1  curr 
    for(int i=start+1; i<end; i++){
        // inc , exc 
   int curr = max((nums[i]+prev2), (0+prev1));
        prev2= prev1;
        prev1= curr;
    }
    return prev1;
}
    int rob(vector<int>& nums) {
          int n= nums.size();
    if(n==1){
        return nums[n-1];
    }
    
    // if first element is included 
    long long int inc = solve(nums, 0, n-1);
    
    // if first element is excluded 
    long long int exc = solve(nums, 1, n);
    return max(inc, exc);
    }
};