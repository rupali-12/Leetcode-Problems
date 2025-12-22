class Solution {
public:
   void swap(vector<int>&nums, int i, int j){
    int temp= nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
   }
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low =0, high = n-1, curr=0;
        while(curr<=high){
            if(nums[curr] ==2){
                swap(nums, curr, high);
                high--;
            }
            else if(nums[curr]==0){
                swap(nums, curr, low);
                low++;
                curr++;
            }
            else{
                curr++;
            }
        }
        return;
    }
};