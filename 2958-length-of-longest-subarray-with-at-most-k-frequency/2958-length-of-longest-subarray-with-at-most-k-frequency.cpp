class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map<int, int>mp;
        int i=0, j=0, result=0;
        
//         // Approach-1: T.C-> O(n2)
//         while(j<n){
//             mp[nums[j]]++;
            
//             while(i<j && mp[nums[j]]>k){
//                 mp[nums[i]]--;
//                 i++;
//             }
            
//             result= max(result, (j-i+1));
//             j++;
//         }
//         return result;
        
        // Approach-2: T.C-> O(n)
        int culprit=0;
        while(j<n){
            mp[nums[j]]++;
            if(mp[nums[j]]==k+1){
                culprit++;
            }
            
            if(culprit>0){
                mp[nums[i]]--;
                if(mp[nums[i]]==k){
                    culprit--;
                }
                i++;
            }
            
            result= max(result, (j-i+1));
            j++;
        }
        
        return result;
    }
};