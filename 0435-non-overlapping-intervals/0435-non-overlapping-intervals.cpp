class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count=0;
        int n= intervals.size();
        sort(intervals.begin(), intervals.end());
        
        int i=0, j=1;
        while(j<n){
            vector<int>curr_interval=intervals[i];
            vector<int>next_interval=intervals[j];
            
            int cs= curr_interval[0];
            int ce=curr_interval[1];
             int ns= next_interval[0];
            int ne= next_interval[1];
            
            // non overlapping 
            if(ce<=ns){
                i=j;
                j++;
            }
            // case of overlapping--> next is deleted
            else if(ce<ne){
                j++;
                count++;
            }
            // case of overlapping--> curr is deleted
            else if(ce>=ne){
                i=j;
                j++;
                count++;
            }
        }
        return count;
    }
};