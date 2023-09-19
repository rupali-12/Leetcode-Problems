class Solution {
public:
    int solveRec(int n){
        if(n==0 || n==1) return 1;
        
        int ans=0;
        for(int i=1; i<=n; i++){
            ans+= solveRec(i-1)*solveRec(n-i);
        }
        return ans;
    }
    int numTrees(int n) {
        // Approach-1: Recursion 
        return solveRec(n);
    }
};