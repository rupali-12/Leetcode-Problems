class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
         int n= intervals.size();
         vector<vector<int>>result;
         auto lambda = [](vector<int>&vec1, vector<int>&vec2){
            if(vec1[0]==vec2[0]){
                return vec1[1]>vec2[1];
            }
            return vec1[0]<vec2[0];
         };
         sort(begin(intervals), end(intervals), lambda);

         result.push_back(intervals[0]);

         for(int i=1; i<n; i++){
            // itheinterval covered by element present at result back
            if(result.back()[1] >= intervals[i][1]){
                continue;
            }
            result.push_back(intervals[i]);
         }
         return result.size();
    }
};