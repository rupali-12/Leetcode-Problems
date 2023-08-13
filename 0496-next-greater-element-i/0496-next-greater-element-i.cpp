class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         stack<int>s;
      unordered_map<int, int>tmp;
      s.push(-1);
         for(int j=nums2.size()-1; j>=0; j--){
              while(s.top()!=-1 && s.top()<nums2[j]){
              s.pop();
          }
             tmp[nums2[j]]= s.top();
          // tmp[j]= s.top();
          s.push(nums2[j]);
      }
       vector<int>ans(nums1.size());
        for(int i=0; i<nums1.size(); i++){
           // if(tmp.find(nums1[i])!=tmp.end()){
                ans[i]= tmp[nums1[i]];
           // }
            // else{
            //     ans[i]= -1;
            // }
        }
      return ans;
    }
};