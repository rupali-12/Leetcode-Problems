class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n= names.size();
        unordered_map<int, string>mp;

        for(int i=0; i<n; i++){
            mp[heights[i]] = names[i];
        }
        
         sort(heights.begin(), heights.end());
        
        vector<string>ans(n);
        int index=0;
        for(int i=n-1; i>=0; i--){
            ans[index++]= mp[heights[i]];
        }
        return ans;
    }
};