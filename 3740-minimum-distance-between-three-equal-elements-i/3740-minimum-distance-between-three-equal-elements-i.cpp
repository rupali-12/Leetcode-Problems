class Solution {
public:

/* 0 1 2 3 4 5 6
1 1 2 3 2 1 2

1- 0 1 5
2- 2 4 6
3- 3 

abs(0-1)+abs(1-5)+abs(5-0) = 1+4+5=10
abs(2-4)+abs(4-6)+abs(6-2) = 2+2+4=8

as a<b<c
abs(a-b)+abs(b-c)+abs(c-a) = b-a + c-b + c-a = 2*(c-a) = 2*(vec[i+1]-vec[i])  */

    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>>mp;
        int n=nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        int mnAns = INT_MAX;
        for(auto &m: mp){
            int num= m.first;
            vector<int>vec = m.second;

            if(vec.size() <3) continue;

            for(int i=0; i+2<vec.size(); i++){
                int dist = 2* (vec[i+2]-vec[i]);
                mnAns =min(mnAns, dist);
            }
        }
        return mnAns==INT_MAX? -1: mnAns;
    }
};

