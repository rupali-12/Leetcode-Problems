class Solution {
public:
typedef long long ll;
    vector<long long> distance(vector<int>& nums) {
        int n= nums.size();
        vector<ll>ans(n, 0);

        // // Approach -1: BRute Force TLE for big constraints
        // unordered_map<int, vector<int>>mp;
        // for(int i=0; i<n; i++){
        //     mp[nums[i]].push_back(i);
        // }

        // for(int i=0; i<n; i++){
        //     int num= nums[i];
        //     ll sum=0;
        //     for(auto v: mp[num]){
        //        if(v != i) sum+= abs(v-i);
        //     }
        //     ans[i] =sum;
        // }
        // return ans;

        // Approach-2: Optimise 
        unordered_map<int, ll>indexCount;   // nums[i] -> freq of i's
        unordered_map<int, ll>indexSum;   // nums[i] -> sum of i's

        // Left to Right
        for(int i=0; i<n; i++){
            ll freq = indexCount[nums[i]];
            ll sum = indexSum[nums[i]];

            ans[i]+= freq*i - sum;

            indexCount[nums[i]] += 1;
            indexSum[nums[i]] += i;
        }

        indexCount.clear();
        indexSum.clear();

        // Right to Left
        for(int i=n-1; i>=0; i--){
            ll freq = indexCount[nums[i]];
            ll sum = indexSum[nums[i]];

            ans[i]+= sum - freq*i;

            indexCount[nums[i]] += 1;
            indexSum[nums[i]] += i;
        }
        return ans;
    }
};