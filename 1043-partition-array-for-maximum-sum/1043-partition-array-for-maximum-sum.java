class Solution {
    private int solveRec(int []arr, int i , int k){
        if(i==arr.length) return 0;
        int len=0, maxi=Integer.MIN_VALUE, maxAns=Integer.MIN_VALUE;
        for(int j=i; j<Math.min(arr.length, i+k); j++){
            len++;
            maxi= Math.max(maxi, arr[j]);
            int sum = (len*maxi) + solveRec(arr, j+1, k);
            maxAns = Math.max(maxAns, sum);
        }
        return maxAns;
    }
    private int solveMem(int []arr, int i , int k, Integer []dp){
        if(i==arr.length) return 0;
        if(dp[i]!=null) return dp[i];
        int len=0, maxi=Integer.MIN_VALUE, maxAns=Integer.MIN_VALUE;
        for(int j=i; j<Math.min(arr.length, i+k); j++){
            len++;
            maxi= Math.max(maxi, arr[j]);
            int sum = (len*maxi) + solveMem(arr, j+1, k, dp);
            maxAns = Math.max(maxAns, sum);
        }
        return dp[i] = maxAns;
    }
    public int maxSumAfterPartitioning(int[] arr, int k) {
        // // Approach-1: Recursion 
        // return solveRec(arr, 0, k);
        
        // Approach-2: Recursion + Mamoization 
        Integer []dp =new Integer[arr.length];
        return solveMem(arr, 0, k, dp);
    }
}