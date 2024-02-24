class Solution {
public:
    typedef pair<int, int>P;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
     
        // make graph
        map<int, vector<pair<int,  int>>>graph;
        // initial insertion 
        graph[0].push_back({firstPerson, 0});
        graph[firstPerson].push_back({0, 0});
        
        for(auto& x: meetings){
            int p1= x[0];
            int p2= x[1];
            int time= x[2];
            graph[p1].push_back({p2, time});
            graph[p2].push_back({p1, time});
        }
        
        vector<int>knowing(n, 0);
        priority_queue<P, vector<P>, greater<P>>pq;
        // bfs 
        // {time, secondPeron}
        pq.push({0, 0});
        pq.push({0, firstPerson});
        while(!pq.empty()){
            auto T = pq.top();
            pq.pop();
            int currTime= T.first, currPerson= T.second;
            if(knowing[currPerson]==1) continue;
            knowing[currPerson]= 1;
            for(auto& neigh: graph[currPerson]){
               int time=neigh.second;
                int person = neigh.first;
                if(!knowing[person] && time>=currTime){
                    pq.push({time, person});
                }
            }
        }
        
        
        vector<int>ans;
        for(int i=0; i<knowing.size(); i++){
            if(knowing[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};