class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // // Approach 1:
        //  int n= intervals.size();
        //  vector<vector<int>>result;
        //  auto lambda = [](vector<int>&vec1, vector<int>&vec2){
        //     if(vec1[0]==vec2[0]){
        //         return vec1[1]>vec2[1];
        //     }
        //     return vec1[0]<vec2[0];
        //  };
        //  sort(begin(intervals), end(intervals), lambda);

        //  result.push_back(intervals[0]);

        //  for(int i=1; i<n; i++){
        //     // itheinterval covered by element present at result back
        //     if(result.back()[1] >= intervals[i][1]){
        //         continue;
        //     }
        //     result.push_back(intervals[i]);
        //  }
        //  return result.size();

        // Approach -2:O(1)
          int n= intervals.size(), lastEnd=0, size=0;
         auto lambda = [](vector<int>&vec1, vector<int>&vec2){
            if(vec1[0]==vec2[0]){
                return vec1[1]>vec2[1];
            }
            return vec1[0]<vec2[0];
         };
         sort(begin(intervals), end(intervals), lambda);

         lastEnd = intervals[0][1];
         size++;

         for(int i=1; i<n; i++){
            // itheinterval covered by element present at result back
            if(lastEnd >= intervals[i][1]){
                continue;
            }
            lastEnd = intervals[i][1];
            size++;
         }
         return size;
    }
};