class Solution {
public:
    int findParent(int element, vector<int>parent){
        if(parent[element]==element) return element;
        return findParent(parent[element], parent);
    }
    
//     // Approach-1: Using disjoint set 
//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//         int n= edges.size();
//         vector<int>parent(n+1);
//         for(int i=0; i<=n; i++){
//             parent[i]=i;
//         }
        
//         // process each edge 
//         for(vector<int>v: edges){
//         // [[1,2],[2,3],[3,4],[1,4],[1,5]]
//             int el1 = v[0];
//             int el2 = v[1];
            
//             int p1 = findParent(el1, parent);
//             int p2 = findParent(el2, parent);
//             if(p1==p2) return v;
//             else{
//                 parent[p2] =p1;
//             }
//         }
//         return {};
//     }
    
    // **************************************************************
     // Approach-2: Using Rank 
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        vector<int>parent(n+1);
        vector<int>rank(n+1);
        for(int i=0; i<=n; i++){
            parent[i]=i;
            rank[i]=1;
        }
        
        // process each edge 
        for(vector<int>v: edges){
        // [[1,2],[2,3],[3,4],[1,4],[1,5]]
            int el1 = v[0];
            int el2 = v[1];
            
            int p1 = findParent(el1, parent);
            int p2 = findParent(el2, parent);
            if(p1==p2) return v;
            else{
                if(rank[p1]<rank[p2]){
                    parent[p1]=p2;
                }
                else if(rank[p1]>rank[p2]){
                    parent[p2]=p1;
                }
                else{
                    parent[p1]=p2;
                    rank[p2]++;
                }
            }
        }
        return {};
    }
};