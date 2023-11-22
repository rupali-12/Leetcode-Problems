class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int>result;
        int m= nums.size();
vector<vector<int>>mp(100001);
        
        // fill map 
        for(int i=0;i<m; i++){
            for(int j=0; j<nums[i].size(); j++){
                mp[i+j].push_back(nums[i][j]);
            }
        }
        
        for(int i=0; i<mp.size(); i++){
           vector<int>temp =mp[i];
            for(int j= temp.size()-1; j>=0; j--){
                result.push_back(temp[j]);
            }
        }
        return result;
    }
};