class Solution {
public:
    int solveMem(int index, string &colors, vector<int>&neededTime, char prevColor, int prevTime, vector<int>&dp){
        if(index<0) return 0;
        
        if(dp[index]!=-1) return dp[index];
        
        // if currcolor same as prevcolor 
        int ans =0;
        if(colors[index]==prevColor){
          ans= solveMem(index-1, colors, neededTime, colors[index], max(neededTime[index], prevTime), dp) + min(neededTime[index], prevTime);  
        }
        else{
         ans= solveMem(index-1, colors, neededTime, colors[index], neededTime[index], dp);   
        }
        return dp[index]=ans;
    }
    int minCost(string colors, vector<int>& neededTime) {
//        // Approach-1: Two pointer Approach 
//         int start=0, end=0;
//         int timeAns=0, n= colors.length();
        
//         while(start<n &&  end<n){
//             int groupTotal =0, maxTime=0;
            
//             while(end<n && colors[start]==colors[end]){
//                 maxTime = max(maxTime, neededTime[end]);
//                 groupTotal+=neededTime[end];
//                 end++;
//             }
//             timeAns+= (groupTotal - maxTime);
//             start= end;
//         }
//         return timeAns;
        
        // Approach-2 : Recursion+Memoization 
        int n= colors.length();
        vector<int>dp(n, -1);
        return solveMem(n-1, colors, neededTime, 'A', neededTime[n-1], dp);
    }
};