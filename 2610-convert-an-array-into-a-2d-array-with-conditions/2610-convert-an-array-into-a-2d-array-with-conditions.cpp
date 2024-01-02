class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int>mp;
        int n=0;
        for(int x: nums){
            mp[x]++;
            n= max(n, mp[x]);
        }
        
         vector<vector<int>>ans(n);
        vector<set<int>>s(n);
        for(int x: nums){
            for(int i=0; i<n; i++){
                if(s[i].find(x)==s[i].end()){
                    ans[i].push_back(x);
                    s[i].insert(x);
                    break;
                }
            }
        }
        return ans;
    }
};