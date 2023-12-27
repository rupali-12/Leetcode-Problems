class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
       // Approach-1: Two pointer Approach 
        int start=0, end=0;
        int timeAns=0, n= colors.length();
        
        while(start<n &&  end<n){
            int groupTotal =0, maxTime=0;
            
            while(end<n && colors[start]==colors[end]){
                maxTime = max(maxTime, neededTime[end]);
                groupTotal+=neededTime[end];
                end++;
            }
            timeAns+= (groupTotal - maxTime);
            start= end;
        }
        return timeAns;
    }
};