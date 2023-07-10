class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>a;
        map<int, int>m;
        for(auto x: nums){
            m[x]++;
        }
        for(auto x:m){
            if(x.second>1){
                a.push_back(x.first);
            }
        }
        return a;
    }
};