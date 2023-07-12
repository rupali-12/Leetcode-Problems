class Solution {
public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         vector<vector<int>>ans;
//         int n= nums.size();
//         sort(nums.begin(), nums.end());
//         for(int i=0; i<n-3;i++){
//             if(i>0 && nums[i]==nums[i-1]){
//                 continue;
//             }
//             for(int j=i+1; j<n-2; j++){
//                   if(j>i+1 && nums[j]==nums[j-1]){
//                 continue;
//             }
                
//                   long long tSum = (long long)target - ((long long)nums[i] + (long long)nums[j]);
//                 int l = j + 1, h = n - 1;
//                 while(l<h){
//                     if(nums[l] + nums[h]==tSum){
//                     ans.push_back({nums[i], nums[j], nums[l], nums[h]});
//                           while(l<h && nums[l]==nums[l+1]){
//                 l++;
//             }
//                         while(l < h && nums[h] == nums[h - 1]){
//                             h--;
//                         }
//                         l++;
//                         h--;
//                     }
//                     else if(nums[l] + nums[h] > (target- (nums[i]+ nums[j]))){
//                         h--;
//                     }
//                     else{
//                         l++;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
    
    // ******************************************************************************
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int low = j+1, high = n-1;
                while(low < high){
                    if(nums[low] + nums[high] < newTarget){
                        low++;
                    }
                    else if(nums[low] + nums[high] > newTarget){
                        high--;
                    }
                    else{
                        output.push_back({nums[i], nums[j], nums[low], nums[high]});
                        int tempIndex1 = low, tempIndex2 = high;
                        while(low < high && nums[low] == nums[tempIndex1]) low++;
                        while(low < high && nums[high] == nums[tempIndex2]) high--;
                    }
                }
                while(j+1 < n && nums[j] == nums[j+1]) j++;
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return output;
    }
};


