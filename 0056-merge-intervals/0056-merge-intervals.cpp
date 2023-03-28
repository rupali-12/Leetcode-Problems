class Solution {
public:
    
     // vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //     sort(intervals.begin(), intervals.end());
    //        vector<vector<int>>ans;
    //     for(int i=0; i<intervals.size(); i++){
    //         if(ans.empty()){
    //             ans.push_back(intervals[i]);
    //         }
    //         else{
    //             vector<int>&v = ans.back();
    //             int y= v[1]; 
    //             if(y>= intervals[i][0]){
    //                 v[1] = max(y, intervals[i][1]);
    //             }
    //             else{
    //                 ans.push_back(intervals[i]);
    //             }
    //         }
    //     }
    //             return ans;
    // }
    
    
    // ************************************************************
     vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
         vector<vector<int>>result;
          for(int i=0; i<intervals.size(); i++){
               if(result.empty()){
                result.push_back(intervals[i]);
             }
             else{
                vector<int>&v = result.back();
                 // if(v[1]>=intervals[i][0]){
                 //     v[1] = max(v[i], intervals[i][1]);
                 // }
                  int y= v[1]; 
                if(y>= intervals[i][0]){
                    v[1] = max(y, intervals[i][1]);
                }
                 else{
                  result.push_back(intervals[i]);
                 }
             }
          }  
          
         return result;
    }

};