class DSU{
  public:
  vector<int>parent, rank;
  DSU(int n){
     parent.resize(n);
     rank.resize(n, 1);

     for(int i=0; i<n; i++){
       parent[i] = i;
     }
  }

  int find(int x){
     if(x==parent[x]){
        return x;
     }

     return parent[x] = find(parent[x]);
  }

  bool Union(int x, int y){
     int x_parent = find(x);
     int y_parent = find(y);

     if(x_parent == y_parent) return false;

     if(rank[x_parent] < rank[y_parent]){
        parent[x_parent] =y_parent;
     }
     else if(rank[x_parent] > rank[y_parent]){
        parent[y_parent] = x_parent;
     }
     else{
        parent[x_parent] =y_parent;
        rank[y_parent]++;
     }
     return true;
  }
};

class Solution {
public:

    bool check(int n, vector<vector<int>>& edges, int k, int mid){
       DSU dsu(n);
       vector<vector<int>>upgradeCandidates;

       for(auto edge: edges){
         int u=edge[0];
         int v=edge[1];
         int s=edge[2];
         int m=edge[3];

         if(m==1){
           if(s<mid){
              return false; 
           }
           dsu.Union(u, v);
         }
         else{
            if(s>=mid){
                // No need to upgrade
                dsu.Union(u, v);
            }
            else if(2*s>=mid){
                upgradeCandidates.push_back({u, v});
            }
         }
       }

    //    check upgraded candidates if they can form edge
    for(auto edge: upgradeCandidates){
      int u= edge[0];
      int v=edge[1];
    //   if they not form edge then only form 
    if(dsu.find(u)!=dsu.find(v)){
        if(k<=0) return false;
        dsu.Union(u, v);
        k--;
    }
    }
       
    //    check if every node has root 
    int root=dsu.find(0);
    for(int i=1; i<n; i++){
        if(dsu.find(i)!=root){
          return false;
        }
    }
    return true;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        // if m==1 wale edged make cycle then forming spanning tree is impossible

        // 0---1----2, parent =0
        // (2, 0)
        // parent of 2 is 0
        // now parent os 0 is 0  // means a cycle 
        DSU dsu(n);
        for(auto &edge: edges){
            int u=edge[0];
            int v=edge[1];
            int s=edge[2];
            int m=edge[3];

            if(m==1){  // must be includfe in spanning tree so checking if the form cycle then return -1
               if(dsu.find(u)==dsu.find(v)){
                return -1;
               }
               dsu.Union(u, v);
            }
        }
        //  start binary search 
        int result =-1;
        int l=1, r= 2*1e5;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(check(n, edges, k, mid)){
                result =mid;
                l= mid+1;
            }
            else{
                r =mid-1;
            }
        }
        return result;
    }
};