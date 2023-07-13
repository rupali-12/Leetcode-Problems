// class Solution {
// public:
    
//     void solve(vector<int>arr, int n, int index, vector<vector<int>>&ans, int  k, vector<int>&v){
//        if(v.size()==k){
//                 ans.push_back(v);
//            return;
//        }
//         if(index>=n){
//             return;
//         }
//         v.push_back(arr[index]);
//         solve(arr, n, index+1, ans, k, v);
//        v.pop_back();
//         solve(arr, n, index+1, ans, k, v);
        
//     }
//     vector<vector<int>> combine(int n, int k) {
//         vector<int>arr(n);
//         for(int i=0; i<n; i++){
//             arr[i]= i+1;
//         }
//        vector< vector<int>>ans;
//         vector<int>v;
//         solve(arr, n, 0, ans, k, v);
//         return ans;
//     }
// };





class Solution {
public:
    void solve(vector<int>& arr, int n, int index, vector<vector<int>>& ans, vector<int>& combination, int k) {
        if (combination.size() == k) {
            ans.push_back(combination);
            return;
        }
        if (index >= n) {
            return;
        }
        combination.push_back(arr[index]);
        solve(arr, n, index + 1, ans, combination, k);
        combination.pop_back();
        solve(arr, n, index + 1, ans, combination, k);
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }
        vector<vector<int>> ans;
        vector<int> combination;
        solve(arr, n, 0, ans, combination, k);
        return ans;
    }
};
