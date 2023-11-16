class Solution {
public:
//     void solveRec(vector<int> &num, int index, int tar, vector<int>&temp, set<vector<int>>&s){
//         if(index>=num.size()){
//             if(tar==0){
//                 s.insert(temp);
//             }
//                 return;
//         }

//        temp.push_back(num[index]);
//         // case of inclusion 
//        solveRec(num, index+1, tar- num[index], temp, s);   
//        temp.pop_back();
           
//     // case of exclusion 
//        solveRec(num, index+1, tar, temp, s);
//    return;
// }   
    
    // optimized 
        void optimized(vector<int> &num, int index, int tar, vector<int>&temp, vector<vector<int>>&ans){
       if(tar==0){
           ans.push_back(temp);
           return;
       }
     for(int i= index; i<num.size(); i++){
         if(i>index && num[i]==num[i-1]) continue;
         
         if(num[i]>tar) break;
         
         temp.push_back(num[i]);
         optimized(num, i+1, tar-num[i], temp, ans);
         temp.pop_back();
     }
   return;
}   

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        // approach-1: 
//         set<vector<int>>s;
//          vector<vector<int>>ans;
//         vector<int>temp;
//         solveRec(candidates,0, target, temp, s);
        
//         for(auto x:s){
//             ans.push_back(x);
//         }
//         return ans;
        
        // Approach-2: Optimized 
         vector<vector<int>>ans;
        vector<int>temp;
        // sort in order to avoid duplicates 
        sort(candidates.begin(), candidates.end());
        optimized(candidates,0, target, temp, ans);
        
        return ans;
    }
};