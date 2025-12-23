class Solution {
public:
int n;
int dp[100001][3];
   int binarySearch(vector<vector<int>>& events, int currEndTime){
      int low= 0;
      int high= n-1;
      int ans=n;
      while(low<=high){
        int mid = low + (high-low)/2;
        if(events[mid][0] > currEndTime){
            ans = mid;
            high= mid-1;
        }
        else{
            low =mid+1;
        }
      }
      return ans;
   }
   int solve(vector<vector<int>>& events, int i, int count){
    if(count==2 || i==n){
        return 0;
    }

    if(dp[i][count]!=-1){
        return dp[i][count];
    }
    
    int nextValidIdx = binarySearch(events, events[i][1]);   // end time of current index i
    int take = events[i][2] + solve(events, nextValidIdx, count+1);
    int notTake = solve(events, i+1, count);
    return dp[i][count] = max(take, notTake);
   }
    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(events.begin(), events.end());\
        memset(dp, -1, sizeof(dp));
        int count=0;
        return solve(events, 0, count);
    }
};