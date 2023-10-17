class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>indegree(n);
        
        // step-1: find indegree 
        for(int i=0; i<n; i++){
            if(leftChild[i]!=-1){
                indegree[leftChild[i]]++;
            }
            if(rightChild[i]!=-1){
                indegree[rightChild[i]]++;
            }
        }
        
        // check node has more than one incoming edge or not 
        int rootCount=0;
        for(int i=0; i<n; i++){
            if(indegree[i]>1){
                return false;   // node has more than one incoming edge
            }
            
            // case of more than one root node 
            if(indegree[i]==0){
                rootCount++;
                if(rootCount>1){
                    return false;
                }
            }
        }
        
        // check root node exist or not 
        if(rootCount==0){
            return false;
        }
        
        // topological sort for nodes having indegree=0 
        stack<int>topoSort;
        vector<bool>visited(n, false);
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                topoSort.push(i);
            }
        }
        
        while(!topoSort.empty()){
            int top= topoSort.top();
            topoSort.pop();
            
            // if already visited (case of cycle exist)
            if(visited[top]){
                return false;
            }
            
            visited[top]=true;
            
            if(leftChild[top]!=-1){
                topoSort.push(leftChild[top]);
            }
            if(rightChild[top]!=-1){
                topoSort.push(rightChild[top]);
            }
        }

        // check if any node that is not visited even single time 
        for(int i=0; i<n; i++){
            if(visited[i]==false){
                return false;
            }
        }
        return true;
    }
};