class Solution {
public:
        // optimized 
        void optimized(int index, int tar, int k, vector<int>&temp, vector<vector<int>>&ans){
      if(tar==0 && temp.size()==k){
          ans.push_back(temp);
          return;
      }
    if(temp.size()<k){
      for(int i= index; i<10; i++){
         if(i>tar) break;
          temp.push_back(i);
           optimized(i+1, tar- i, k, temp, ans);  
          temp.pop_back();
         }
      }
   return;
}   
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
          vector<vector<int>>ans;
        vector<int>temp;

        // index, target, numofelement 
        optimized(1, n, k,  temp, ans);
        
        return ans;
    }
};