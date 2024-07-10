class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        // Approach-1: Brute force 
        int depth=0;
        for(string str: logs){
            if(str=="../"){
                // depth--;
                // if(depth<0) depth=0;
                
                depth= max(0, depth-1);
            }
            else if(str=="./") continue;
            else depth++;
        }
        return depth;
    }
};