class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int, pair<int, int>>>maxi;
        for(int i=0; i<points.size(); i++){
            maxi.push({(points[i][0]*points[i][0] + points[i][1]*points[i][1]), {points[i][0], points[i][1]}});
            
            // if maxi size is greater than k then pop from queue
            if(maxi.size() >k){
                maxi.pop();
            }
        }
        
        // store ans -> heap contain only k eleements right now 
        while(maxi.size()>0){
            pair<int, int>p = maxi.top().second;
            ans.push_back({p.first, p.second});
            maxi.pop();
        }
        return ans;
    }
};