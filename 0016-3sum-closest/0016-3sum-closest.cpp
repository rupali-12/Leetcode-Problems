class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = INT_MAX, result = 0;
        int n = nums.size();
        
        // sort 
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++){
            int k=i+1;
            int j=n-1;
            while(k<j){
                int sum =  nums[i]+nums[k]+nums[j];
                if(sum==target){
                    return sum;
                }
                else if(abs(sum-target)<abs(ans)){
                    ans = sum- target;   // update min difference
                    result = sum;   // update closest sum 
                }
                
                if(sum>target){  // if sum is large then shift right pointer
                    j--;
                }
                else{
                    k++;
                }
            }
        }
        return result;
    }
};