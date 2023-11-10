class Solution {
public:
    void dfs(unordered_map<int, vector<int>>&mp, set<int>&vis, int a, vector<int>&ans){
        if(vis.find(a)!=vis.end()) return;
        ans.push_back(a);
        vis.insert(a);
        for(auto neigh: mp[a]){
            dfs(mp, vis, neigh, ans);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>>mp;
        for(auto a: adjacentPairs){
            int u= a[0];
            int v= a[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        
        // Find first element of array which appear only once 
        int firstElement;
        for(auto a: mp){
            if(a.second.size()==1){
                firstElement= a.first;
            }
        }
        vector<int>ans;
        set<int>vis;
    
        // Do DFS 
      dfs(mp, vis, firstElement, ans);
        return ans;
        
        
    }
};