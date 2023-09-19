class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        // <prev temp (current element-diff), temp ans(no. of timesthe temp occor previously other than current)>
        unordered_map<int, int>dp;
        int ans=0;
       for(int i=0; i<arr.size(); i++){
           int temp = arr[i]-difference;
            int tempAns=0;
           
           // check if ans for temp already exist or not
           if(dp.count(temp)){
               tempAns= dp[temp];    // +1 to store current ans 
           }
           
               dp[arr[i]] = 1+ tempAns;
           ans= max(ans, dp[arr[i]]);
       }
        return ans;
    }
};