class Solution {
public:
   typedef pair<int, int> P;

   int findDist(vector<int>a, vector<int>b){
    int dis = (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
    return dis;
   }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<P>pq;
        int n = points.size();
        vector<vector<int>>ans(k);
        for(int i=0; i<n; i++){
            int dist = findDist(points[i], {0,0});
            pq.push({dist, i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        int i=0;
        while(!pq.empty()){
            int idx = pq.top().second;
            pq.pop();
            ans[i] =points[idx];
            i++;
        }
        return ans;
    }
};