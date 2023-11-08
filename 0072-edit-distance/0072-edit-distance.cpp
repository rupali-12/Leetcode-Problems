class Solution {
public:
    int solveRec(string word1, string word2, int i, int j){
       if(i==word1.length()){
           return word2.length()-j;
       }
        if(j==word2.length()){
           return word1.length()-i;
       }
        int ans= INT_MAX;
        if(word1[i]==word2[j]){
            return solveRec(word1, word2, i+1, j+1);
        }
        else{
            // insert 
            int insertAns=  1+ solveRec(word1, word2, i, j+1);
            
            // delete 
             int deleteAns=  1+ solveRec(word1, word2, i+1, j);
            
            // replace 
             int replaceAns=  1+ solveRec(word1, word2, i+1, j+1);
            ans= min(insertAns, min(deleteAns, replaceAns));
        }
        return ans;
    }
     int solveMem(string word1, string word2, int i, int j, vector<vector<int>>&dp){
       if(i==word1.length()){
           return word2.length()-j;
       }
        if(j==word2.length()){
           return word1.length()-i;
       }
         if(dp[i][j]!=-1){
             return dp[i][j];
         }
        int ans= INT_MAX;
        if(word1[i]==word2[j]){
            return solveRec(word1, word2, i+1, j+1);
        }
        else{
            // insert 
            int insertAns=  1+ solveRec(word1, word2, i, j+1);
            
            // delete 
             int deleteAns=  1+ solveRec(word1, word2, i+1, j);
            
            // replace 
             int replaceAns=  1+ solveRec(word1, word2, i+1, j+1);
            ans= min(insertAns, min(deleteAns, replaceAns));
        }
        return dp[i][j]= ans;
    }
    int solveTab(string word1, string word2){
     vector<vector<int>>dp(word1.length()+1, vector<int>(word2.length()+1, 0)); 
        for(int j=0; j<word2.length(); j++){
            dp[word1.length()][j]= word2.length()-j;
        }
        for(int i=0; i<word1.length(); i++){
            dp[i][word2.length()]= word1.length()-i;
        }
        
        for(int i=word1.length()-1; i>=0; i--){
            for(int j= word2.length()-1;  j>=0; j--){
                int ans= 0;
                if(word1[i]==word2[j]){
                    ans = dp[i+1][j+1];
                }
                else{
                    int insertAns = 1 + dp[i][j+1];
                    int deleteAns = 1 + dp[i+1][j];
                    int replaceAns = 1 + dp[i+1][j+1];
                    ans= min(insertAns, min(deleteAns, replaceAns));
                }
                dp[i][j]= ans;
            }
        }
        return dp[0][0];
    }
    int solveTabSpOpt(string word1, string word2){
        if(word1.length()==0 && word2.length()==0) return 0;
        if(word1.length()==0 || word2.length()==0) return 1;
       vector<int>curr(word2.length()+1, 0);
         vector<int>next(word2.length()+1, 0);
        
       // Base case 
         for(int j=0; j<word2.length(); j++){
            next[j]= word2.length()-j;
        }
       
        
        for(int i=word1.length()-1; i>=0; i--){
            for(int j= word2.length()-1;  j>=0; j--){
                curr[word2.length()] = word1.length()-i;
                int ans= 0;
                if(word1[i]==word2[j]){
                    ans = next[j+1];
                }
                else{
                    int insertAns = 1 + curr[j+1];
                    int deleteAns = 1 + next[j];
                    int replaceAns = 1 + next[j+1];
                    ans= min(insertAns, min(deleteAns, replaceAns));
                }
                curr[j]= ans;
            }
            next=curr;
        }
        return next[0];
        
    }
    
    int minDistance(string word1, string word2) {
        // // Approach-1: Recursion 
        // return solveRec(word1, word2, 0, 0);
        
        // // Approach-2: Recursion + Memoization
        // vector<vector<int>>dp(word1.length(), vector<int>(word2.length(), -1));
        // return solveMem(word1, word2, 0, 0, dp);
        
//            // Approach-3: Tabulation
//         return solveTab(word1, word2);
        
                
           // Approach-4: Tabulation + space Optimization
        return solveTabSpOpt(word1, word2);

    }
};