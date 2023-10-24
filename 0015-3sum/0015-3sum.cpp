class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Approach-1: using set(hashing)
//         set<vector<int>>st;
//         for(int i=0; i<nums.size(); i++){
//             set<int>hashSet;
//             for(int j=i+1; j<nums.size(); j++){
//                 int third = -(nums[i]+nums[j]);
//                 if(hashSet.find(third)!=hashSet.end()){
//                     vector<int>temp= {nums[i], nums[j], third};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//                 hashSet.insert(nums[j]);
//             }
//         }
        
//         vector<vector<int>>ans(st.begin(), st.end());
//         return ans;
        
        // Approach-2: Optimized Approach 
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            // skip same elements 
            if(i>0 && nums[i]==nums[i-1]) continue;
            
            int j= i+1, k= nums.size()-1;
            while(j<k){
                int sum= nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    vector<int>temp={nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    ans.push_back(temp);
                    j++; k--;
                    
                    // skip same elements 
                    while(j<k && nums[j]==nums[j-1]){
                        j++;
                    }
                    while(j<k && nums[k]==nums[k+1]){
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};