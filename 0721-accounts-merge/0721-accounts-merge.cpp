class Disjoint{
    public:
    vector<int>parent, rank;
    Disjoint(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for(int i=0; i<=n; i++){
            parent[i]=i;
        }
    }
    
    int findParent(int node){
        if(node==parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void unionByRank(int u, int v){
        u = findParent(u);
        v= findParent(v);
        
        if(rank[u]<rank[v]){
            parent[u] =v;
        }
        else if(rank[v]<rank[u]){
            parent[v] =u;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
        return;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        Disjoint ds(n);
        
        unordered_map<string, int>mailNodeMap;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                if(mailNodeMap.find(accounts[i][j])==mailNodeMap.end()){
                    mailNodeMap[accounts[i][j]] = i;
                }
                else{
                    ds.unionByRank(i, mailNodeMap[accounts[i][j]]);
                }
            }
        }
        
        vector<string>mergeMail[n];
        for(auto it: mailNodeMap){
            string mail= it.first;
            int node= ds.findParent(it.second);
            mergeMail[node].push_back(mail);
        }
        
        vector<vector<string>>ans;
        for(int i=0; i<n; i++){
            if(mergeMail[i].size()==0) continue;
            vector<string>temp;
            // push name first
            // sort first 
            sort(mergeMail[i].begin(), mergeMail[i].end());
            temp.push_back(accounts[i][0]);
            // now push mail 
            for(auto mail: mergeMail[i]){
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};