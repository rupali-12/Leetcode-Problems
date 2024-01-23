class Solution {
public:
    
    bool dfs(vector<int>&arr, vector<bool>&vis, int start){
         if(start<0 || start>=arr.size() || vis[start]){
             return false;
         }
           if(arr[start]==0){
               return true;
           }
          vis[start] = true;
           return dfs(arr,vis, start+arr[start]) || dfs(arr, vis, start-arr[start]);
       
    }
    bool canReach(vector<int>& arr, int start) {
        int n= arr.size();
        vector<bool>vis(n, false);
        return dfs(arr, vis, start);
    }
};