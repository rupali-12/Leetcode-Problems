class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
         sort(arr.begin(), arr.end());
         vector<vector<int>>ans;
         int minDiff=INT_MAX;
         for(int i=0; i<arr.size()-1; i++){
            int diff = arr[i+1]-arr[i];
            if(diff < minDiff){
                minDiff = diff;
                ans={};
                ans.push_back({arr[i], arr[i+1]});
            }
            else if(arr[i+1]-arr[i] == minDiff){
                ans.push_back({arr[i], arr[i+1]});
            }
         }
         return ans;
    }
};