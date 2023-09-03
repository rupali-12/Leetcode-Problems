class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // step-1 : push newinterval int given array 
        intervals.push_back(newInterval);
        
        // sort by start time 
        sort(intervals.begin(), intervals.end());
        
        // Apply merge Interval 
        int n= intervals.size();
        vector<vector<int>>ans;
        for(int i=0; i<n; i++){
            if(ans.empty() || ans.back()[1]<intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1]= max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};