class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>ans;
        unordered_map<int, int>mp;
        for(int i=0; i<arr1.size(); i++){
            mp[arr1[i]]++;    
        }
        
        for(int i=0; i<arr2.size(); i++){
           int count = mp[arr2[i]];
            while(count--){
                ans.push_back(arr2[i]);
            }
            mp.erase(arr2[i]);
        }
        
        int sizeToBeSorted= ans.size();
        
        // now push remaining element 
        for(auto m: mp){
            int count=m.second;
            while(count--){
                ans.push_back(m.first);
            }
        }
        
        // sort element from sizeTBeSorted to end of ans array 
        sort(ans.begin()+sizeToBeSorted, ans.end());
        
        return ans;
    }
};