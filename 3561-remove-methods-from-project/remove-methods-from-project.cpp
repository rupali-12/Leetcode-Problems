class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        vector<int>inDegree(n, 0);
        vector<bool>suspicious(n, false);

        for(auto edge: invocations){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        queue<int>que;
        que.push(k);
        suspicious[k]=true;
        while(!que.empty()){
            int curr= que.front();
            que.pop();
            for(auto neigh: adj[curr]){
                inDegree[neigh]--;
                if(!suspicious[neigh]){
                    que.push(neigh);
                    suspicious[neigh]=true;
                }
            }
        }

        vector<int>ans;
        bool cannotRemove=false;
        for(int i=0; i<n; i++){
            if(suspicious[i] && inDegree[i]>0){
                cannotRemove=true;
                break;
            }
            if(!suspicious[i]){
                ans.push_back(i);
            }
        }
        
        if(cannotRemove){
            vector<int>vec(n);
            for(int i=0; i<n; i++){
                vec[i]=i;
            }
            return vec;
        }
        return ans;
    }
};