class Solution {
public:
    int n;
    vector<int>dp;
    int solve(int i, vector<int>&arr, vector<bool>&vis){
        if(i<0 || i>=n) return 1e9;
        if(i==n-1) return 0;
        if(vis[i]) return 1e9;
        if(dp[i]!=-1) return dp[i];

        vis[i]=true;
         int ans = 1e9;
        //  forward
        ans = min(ans, 1+solve(i+1, arr, vis));

        // backward
        ans= min(ans, 1+solve(i-1, arr, vis));

        for(int j=0; j<n; j++){
            if(j!=i && arr[i]==arr[j]){
                ans = min(ans, 1+solve(j, arr, vis));
            }
        }
        vis[i] =false;
       return ans;
    }
    int minJumps(vector<int>& arr) {
        n=arr.size();
        vector<bool>vis(n, false);

        // // Approach -1: Recursion + Memoization
        // dp.assign(n, -1);
        // return solve(0, arr, vis);

        // Approach-2: Bottom-up
       unordered_map<int, vector<int>>mp;

    //    store indices having sqame value4
    for(int i=0; i<n; i++){
        mp[arr[i]].push_back(i);
    }

    queue<int>q;
    q.push(0);
    vis[0]=true;
    int jumps=0;
    while(!q.empty()){
        int size=q.size();
        while(size--){
        int i=q.front();
        q.pop();
        // reached end
         if(i == n - 1)
            return jumps;

        // forward
        if(i+1<n && !vis[i+1]){
            vis[i+1]=true;
            q.push(i+1);
        }

        // backward
        if(i-1>=0 && !vis[i-1]){
            vis[i-1]=true;
            q.push(i-1);
        }

        // same value jumps
        for(int idx: mp[arr[i]]){
           if(!vis[idx]){
            vis[idx]=true;
            q.push(idx);
           }
        }
        mp[arr[i]].clear();
        }
        jumps++;
    }
    return jumps;
    }
};