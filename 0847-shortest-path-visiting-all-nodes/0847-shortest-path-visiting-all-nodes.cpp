class Solution {
public:
    typedef pair<int,int> P;
    int shortestPathLength(vector<vector<int>>& graph) {
        int n= graph.size();
        if(n==1 || n==0) return 0;
        set<P>visited;
        queue<P>q;
        
        // Do BFS for all nodes
        for(int i=0; i<n; i++){
            int mask = 1<<i;
            q.push({i, mask});
            visited.insert({i, mask});
        }
        int allVisitedState =  (1<<n) -1; // pow(2, n)-1  
            int path =0;
        while(!q.empty()){
            int size= q.size();
            path++;
            while(size--){
                auto curr = q.front();
                q.pop();
                int currnode =curr.first;
                int currmask =curr.second;
                
                // process neigh 
                for(auto neigh: graph[currnode]){
                    // here we need or as we need to process currmask and current set bit of neigh 
                    int nextmask = currmask | (1<<neigh);
                    
                    if(nextmask==allVisitedState){
                        return path;
                    }
                    
                    // if {neigh, nextmask} is not visited then push in queue and viisted 
                    if(visited.find({neigh, nextmask})==visited.end()){
                        visited.insert({neigh, nextmask});
                        q.push({neigh, nextmask});
                    }
                } 
            }
        }
        return -1; // if no path is found
    }
};