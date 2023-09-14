class Solution {
public:
    int solveRec(int n, vector<int>& days, vector<int>& costs, int index){
        if(index==n) return 0;
        
        // 1 day pass 
        int option1= costs[0]+ solveRec(n, days, costs, index+1);
        
        // 7 day pass 
        // we need to find index for which next call is made 
        int i;
        for(i= index; i<n && days[i]<days[index]+7; i++);
        int option2= costs[1] + solveRec(n, days, costs, i);
        
         // 30 day pass 
        // we need to find index for which next call is made 
        for(i= index; i<n && days[i]<days[index]+30; i++);
        int option3= costs[2] + solveRec(n, days, costs, i);
        
        int ans = min(option1, min(option2, option3));
        return ans;
    }
    
       int solveMem(int n, vector<int>& days, vector<int>& costs, int index, vector<int>&dp){
        if(index==n) return 0;
        if(dp[index]!=-1) return dp[index];
           
        // 1 day pass 
        int option1= costs[0]+ solveMem(n, days, costs, index+1, dp);
        
        // 7 day pass 
        // we need to find index for which next call is made 
        int i;
        for(i= index; i<n && days[i]<days[index]+7; i++);
        int option2= costs[1] + solveMem(n, days, costs, i, dp);
        
         // 30 day pass 
        // we need to find index for which next call is made 
        for(i= index; i<n && days[i]<days[index]+30; i++);
        int option3= costs[2] + solveMem(n, days, costs, i, dp);
        
        int ans = min(option1, min(option2, option3));
        return dp[index]= ans;
    }
    
           int solveTab(int n, vector<int>& days, vector<int>& costs){
           vector<int>dp(n+1, 0);
       for(int index=n-1; index>=0; index--){
            // 1 day pass 
        int option1= costs[0]+ dp[index+1];
        
        // 7 day pass 
        // we need to find index for which next call is made 
        int i;
        for(i= index; i<n && days[i]<days[index]+7; i++);
        int option2= costs[1] +dp[i];
        
         // 30 day pass 
        // we need to find index for which next call is made 
        for(i= index; i<n && days[i]<days[index]+30; i++);
        int option3= costs[2] + dp[i];
        
        int ans = min(option1, min(option2, option3));
           dp[index] = ans;
       }
        return dp[0];
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
       int n = days.size();
        // // Approach-1: Recursion 
        // return solveRec(n, days, costs, 0);
        
        // // Approach-2: Memozation 
        // vector<int>dp(n+1, -1);
        // return solveMem(n, days, costs, 0, dp);
        
        // // Approach-3: Tabulation 
        // return solveTab(n, days, costs);
        
        // Approach -4: Optimized 
        queue<pair<int, int>>monthly;
        queue<pair<int, int>>weekly;
        int ans=0;
        for(auto day: days){
            // 1: Remove expired days from queue 
            while(!monthly.empty() && monthly.front().first + 30 <= day){
                monthly.pop();
            }
             while(!weekly.empty() && weekly.front().first + 7 <= day){
                weekly.pop();
            }
            
            // 2: add current day's cost 
            monthly.push(make_pair(day, ans+costs[2]));
            weekly.push(make_pair(day, ans+costs[1]));
            
            // 3: update ans 
            ans = min(ans+costs[0], min(monthly.front().second, weekly.front().second));
        }
        return ans;
    }
};