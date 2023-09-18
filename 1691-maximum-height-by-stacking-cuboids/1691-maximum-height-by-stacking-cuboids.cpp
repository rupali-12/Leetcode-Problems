class Solution {
public:
    bool check(vector<int>&base, vector<int>&newBox){
        if(base[0]>=newBox[0] &&  base[1]>=newBox[1] && base[2]>=newBox[2]){
            return true;
        }
        return false;
    }
   int solveRec(vector<vector<int>>& cuboids, int prev, int curr){
       if(curr==cuboids.size()) return 0;
       
       // case of include 
       int take=0;
        if(prev==-1 || check(cuboids[curr], cuboids[prev])){
            take = cuboids[curr][2] + solveRec(cuboids, curr, curr+1);
        }
       // case of exclude 
       int notTake = 0+ solveRec(cuboids, prev, curr+1);
       int ans= max(take, notTake);
       return ans;
   }
      int solveMem(vector<vector<int>>& cuboids, int prev, int curr,  vector<vector<int>>&dp){
       if(curr==cuboids.size()) return 0;
       if(dp[curr][prev+1]!=-1){
           return dp[curr][prev+1];
       }
       // case of include 
       int take=0;
          
        if(prev==-1 || check(cuboids[curr], cuboids[prev])){
            cout<<check(cuboids[curr], cuboids[prev])<<endl;
            take = cuboids[curr][2] + solveRec(cuboids, curr, curr+1);
        }
       // case of exclude 
       int notTake = 0+ solveRec(cuboids, prev, curr+1);
       int ans= max(take, notTake);
       return dp[curr][prev+1] =ans;
   }
    int solveTab(vector<vector<int>>& cuboids){
        int n= cuboids.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int curr= n-1; curr>=0; curr--){
            for(int prev = curr-1; prev>=-1; prev--){
                int take=0;
                if(prev==-1 || check(cuboids[curr], cuboids[prev])){  // here we areaccessing prev in cuboid vector not in dp that's why prev not prev+1
                    take = cuboids[curr][2] + dp[curr+1][curr+1];   // now curr become prev but prev is equivalent to prev+1 due to avoid some cases of prev=-1
                }
                 
                int nottake = 0 + dp[curr+1][prev+1];
                dp[curr][prev+1] = max(take, nottake);
            }
        }
        return dp[0][0];   // -1 is equivalent to 0 so , prev= prev+1 
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        int n= cuboids.size();
        // step-1>> sort all dimensions of all cuboids 
       for(auto &a: cuboids){
           sort(a.begin(), a.end());
       }
        
        // step-2>> sort all cuboids based on width 
       sort(cuboids.begin(), cuboids.end());
        
        // // step-3> solve - Recursion 
        // return solveRec(cuboids, -1, 0);
        
        // // // step-3> solve - Memoization 
        // vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        // return solveMem(cuboids, -1, 0, dp);
        
        // // step-3> solve - Tabulation 
        return solveTab(cuboids);
        
    }
};