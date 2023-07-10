class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        // Approach-1: Using map
        // vector<int>a;
        // map<int, int>m;
        // for(auto x: nums){
        //     m[x]++;
        // }
        // for(auto x:m){
        //     if(x.second>1){
        //         a.push_back(x.first);
        //     }
        // }
        // return a;
        
        // Approach-2: Using sorting
        vector<int>ans;
        sort(nums.begin(), nums.end());
        pair<int,int>p= {nums[0], 1};
        
           // no need to handle separately 
         // if(nums.size()==1){
         //     return ans;
         // }
        for(int i=1; i<nums.size(); i++){
            if(nums[i]!= nums[i-1]){
                if(p.second>1){
                    ans.push_back(p.first);
                }
                 p= {nums[i], 1};
            }
            else{
                p.second++;
                if(i==nums.size()-1){
                    ans.push_back(p.first);
                }
            }
        }
        if(ans.size()==0 && p.second>1){
            ans.push_back(nums[0]);
        }
        return ans;
    }
};