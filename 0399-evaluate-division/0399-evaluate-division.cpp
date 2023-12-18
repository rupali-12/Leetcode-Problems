class Solution {
public:
     unordered_map<string, unordered_map<string, double>> buildGraph(vector<vector<string>>& equations, vector<double>& values){
         unordered_map<string, unordered_map<string, double>>graph;
        for(int i=0; i<equations.size(); i++){
            string divident= equations[i][0];
            string divisor = equations[i][1];
            double value= values[i];
            
           graph[divident][divisor] = value;
           graph[divisor][divident] = 1.0/value;
        }
        return graph;
    }
    
    void dfs(string node, string dest, unordered_map<string, unordered_map<string, double>>graph, unordered_set<string>vis, double &ans, double temp){
        if(vis.find(node)!=vis.end()) return;  // keep track to visited all nodes exactly once
           vis.insert(node);
           if(node==dest){
               ans= temp;
               return;
           }
           
           // process neighbour 
           for(auto neigh: graph[node]){
               dfs(neigh.first, dest, graph, vis, ans, temp*neigh.second);
           }
           return;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // <u, <v, w>>
        unordered_map<string, unordered_map<string, double>>graph = buildGraph(equations, values);
        vector<double>result;
        for(auto query:queries){
            string divident = query[0];
            string divisor =query[1];
            
            if(graph.find(divident)==graph.end() || graph.find(divisor)==graph.end()){
                result.push_back(-1);
            }
            else{
                unordered_set<string>vis;
                double ans = -1, temp=1.0;
                dfs(divident, divisor, graph, vis, ans, temp);
                result.push_back(ans);
            }
        }
            return result;
    }
};