class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>>mp;
        int n=nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        int mnAns = INT_MAX;
        for(auto m: mp){
            int num =m.first;
            vector<int>vec = m.second;
            if(vec.size() <3) continue;

            for(int i=0; i+2<vec.size(); i++){
                int dist = 2*(vec[i+2] - vec[i]);
                mnAns = min(mnAns, dist);
            }
        }
        return mnAns == INT_MAX ? -1 : mnAns;
    }
};
