class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       stack<int>s;
        unordered_map<int, int>tmp;
        s.push(-1);
        for(int i= nums2.size()-1; i>=0; i--){
            while(s.top()!=-1 && s.top()<nums2[i]){
                s.pop();
            }
            
            tmp[nums2[i]]= s.top();
            
            // update stack 
            s.push(nums2[i]);
        }
        
        vector<int>ans(nums1.size());
        for(int i=0; i<nums1.size(); i++){
            ans[i]= tmp[nums1[i]];
        }
        return ans;
       
    }
};