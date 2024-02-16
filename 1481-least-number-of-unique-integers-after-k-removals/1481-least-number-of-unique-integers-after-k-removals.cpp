class Solution {
public:
   static bool comp(pair<int, int>&a, pair<int, int>&b){
        return a.second < b.second;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int>mp;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        vector<pair<int, int>>v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), comp);
        for(auto &a:v){
            int count= a.second;
            if(count<=k){
                a.second=0;
                k-=count;
            }
            if(k<=0) break;
        }
        int ans=0;
        for(auto a: v){
            if(a.second!=0) ans++;
        }
        return ans;
    }
};