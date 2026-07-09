class Solution {
public:
vector<int>parent, rank;
     int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x] = find(parent[x]);
     }

    //  union by rank
    void unite(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px==py) return;
        if(rank[x]<rank[y]){
            swap(px, py);
        }
        parent[py] =px;
        if(rank[px] == rank[py]){
            rank[px]++;
        }
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool>ans;
        parent.resize(n);
        rank.assign(n, 0);

        // Initially every node is its own parent
        for (int i = 0; i < n; i++)
            parent[i] = i;
        
        // Connect adjacent indices whenever possible
        for(int i=0; i<n-1; i++){
            if(nums[i+1]-nums[i] <= maxDiff){
                unite(i, i+1);
            }
        }

        for(auto q: queries){
            ans.push_back(find(q[0]) == find(q[1]));
        }
        return ans;
    }
};