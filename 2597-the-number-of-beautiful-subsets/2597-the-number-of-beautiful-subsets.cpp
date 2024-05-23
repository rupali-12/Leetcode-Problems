class Solution {
public:
    
    void solve(int i, vector<int>&nums, vector<int>temp,  vector<vector<int>>&allPosibilities){
        if(i==nums.size()){
            if(temp.size()!=0){   // only non empty subset
                sort(temp.begin(), temp.end());
                allPosibilities.push_back(temp);
            }
            return;
        }
        
        temp.push_back(nums[i]);
        solve(i+1, nums, temp, allPosibilities);
        temp.pop_back();
        solve(i+1, nums, temp, allPosibilities);
    }
    
    
    bool isBeautiful(vector<int>subset, int k){
        for(int i=0; i<subset.size()-1; i++){
                if(abs(subset[i]-subset[i+1])==k){
                    return false;
                }
        }
        return true;
    }
    
    void optimizedSolve(int i, vector<int>&nums, unordered_map<int, int>&mp, int k, int &count){
        if(i==nums.size()){
            count++;
            return;
        }
        
        // not take 
        optimizedSolve(i+1, nums, mp, k, count);
        
        // take 
        if(!mp[nums[i]+k] && !mp[nums[i]-k]){
            mp[nums[i]]++;
            optimizedSolve(i+1, nums, mp, k, count);
            // backtrack
            mp[nums[i]]--;
        }
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
//         // Approach--1 Brute force 
//         vector<vector<int>>allPosibilities;
//         vector<int>temp;
//         solve(0, nums, temp, allPosibilities);
        
//         int count=0;
//         for(int i=0; i<allPosibilities.size(); i++){
//             if(isBeautiful(allPosibilities[i], k)){
//                 count++;
//             }
//         }
//         return count;
        
        // Approach-2: Optimized using map
        int count=0;
        unordered_map<int, int>mp;
        optimizedSolve(0, nums, mp, k, count);
        return count-1;  // count include empty subset as well i.e why count-1 to eliminate empty subset 
        
    }
};