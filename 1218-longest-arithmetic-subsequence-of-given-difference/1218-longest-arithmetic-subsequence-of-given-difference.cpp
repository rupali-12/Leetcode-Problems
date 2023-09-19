class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        // <prev temp (current element-diff), temp ans(no. of timesthe temp occor previously other than current)>
        unordered_map<int, int>dp;
        int ans=0;
       for(int i=0; i<arr.size(); i++){
           int temp = arr[i]-difference;
            
           // check if ans for temp already exist or not
           if(dp.find(temp)!=dp.end()){
               dp[arr[i]] = 1 + dp[temp];    // +1 to store current ans 
           }
           else{
               dp[arr[i]] = 1+0;
           }
           ans= max(ans, dp[arr[i]]);
       }
        return ans;
    }
};