class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>ans(n, 0);
        stack<pair<int, int>>s;
        s.push({temperatures[n-1], n-1});
        
        for(int i=n-2; i>=0; i--){
            while(!s.empty() && temperatures[i]>= s.top().first){
                s.pop();
            }
            
           // if !s.empty then only you nedd to update ans at that index else left it as 0
            if(!s.empty()){
              ans[i] = s.top().second - i;
            }
            
            s.push({temperatures[i], i});
        }
        return ans;
    }
};