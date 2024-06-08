class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        
//         // Approach-1: Brute force Give TLE 
//         for(int i=0; i<n-1; i++){
//             int len=1, sum=nums[i];
//             for(int j=i+1; j<n; j++){
//                 len++;
//                 sum+= nums[j];
//                 if(len>=2 && (sum%k)==0) return true;
//             }
//         }
//         return false;
        
        // Approach-2: Optimized Using Hash Map
        unordered_map<int, int>mp;   // <remainder, index>
        // handle case of rem=0 
        mp[0]=-1;
        int currSum=0;
        for(int i=0; i<n; i++){
            currSum+= nums[i];
            int currRem= currSum%k;
            if(currRem>=0 && mp.find(currRem)!= mp.end()){
                int len = i - mp[currRem];
                if(len>=2){
                  return true;   
                }
            }
            else{
                mp[currRem]=i;
            }
        }
        return false;
    }
};