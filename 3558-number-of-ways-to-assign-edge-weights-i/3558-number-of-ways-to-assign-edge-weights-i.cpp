class Solution {
public:
    typedef long long ll;
    ll M = 1e9+7;
    int getMaxDepth(unordered_map<int, vector<int>>&adj, int root, int parent){
      int mxDepth=0;

      for(auto &ngbr: adj[root]){
        if(ngbr == parent) continue;
        mxDepth = max(mxDepth, getMaxDepth(adj, ngbr, root)+1);
      }
      return mxDepth;
    }

    ll power(ll base, ll exp){
       if(exp==0) return 1;
       ll half = power(base, exp/2);
       ll res = (half*half)%M;
       if(exp%2==1){
        res = (res*base)%M;
       }
       return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>adj;

        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int d = getMaxDepth(adj, 1, -1);
        return power(2, d-1);
    }
};