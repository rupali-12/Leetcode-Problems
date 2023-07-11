class Solution {
public:
  int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
      // Approach-1>> Brute force 
    // long long mx = INT_MIN;
    // if (abs(points[0][0] - points[1][0]) <= k) {
    //     mx = points[0][1] + points[1][1] + abs(points[0][0] - points[1][0]);
    // }
    // if (points.size() == 2) {
    //     return mx;
    // }
    // for (int i = 0; i < points.size() - 1; i++) {
    //     for (int j = i + 1; j < points.size(); j++) { // Fix: j = i + 1
    //         if (abs(points[i][0] - points[j][0]) <= k) {
    //             long long val = points[i][1] + points[j][1] + abs(points[i][0] - points[j][0]);
    //             mx = max(mx, val);
    //         } else {
    //             continue;
    //         }
    //     }
    // }
    // return mx;
      
      // Approach-2>> using max heap 
      priority_queue<pair<int, int>>p;
      int ans=INT_MIN;
      for(int i=0; i<points.size(); i++){
          while(!p.empty() && (points[i][0]- p.top().second)>k){
              p.pop();
          }
          if(!p.empty()){
              ans= max(ans, (points[i][1]+points[i][0]+p.top().first));
          }
          p.push({points[i][1]-points[i][0], points[i][0]});
      }
      return ans;
}
};



