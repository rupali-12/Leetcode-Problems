class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
//         // Approach-1: using map 
//         vector<int>ans;
//         unordered_map<int, int>mp;
//         for(int i=0; i<arr1.size(); i++){
//             mp[arr1[i]]++;    
//         }
        
//         for(int i=0; i<arr2.size(); i++){
//            int count = mp[arr2[i]];
//             while(count--){
//                 ans.push_back(arr2[i]);
//             }
//             mp.erase(arr2[i]);
//         }
        
//         int sizeToBeSorted= ans.size();
        
//         // now push remaining element 
//         for(auto m: mp){
//             int count=m.second;
//             while(count--){
//                 ans.push_back(m.first);
//             }
//         }
        
//         // sort element from sizeTBeSorted to end of ans array 
//         sort(ans.begin()+sizeToBeSorted, ans.end());
        
//         return ans;
        // *******************************************************************
         // Approach-2: using lambda function 
        unordered_map<int, int>mp;
        for(int i=0; i<arr2.size(); i++){
            mp[arr2[i]]=i;    
        }
        
        for(int i=0; i<arr1.size(); i++){
           if(!mp.count(arr1[i])){
               mp[arr1[i]]= INT_MAX;
           }
        }
        
        // sort element using lambda function 
        
        auto lambda = [&](int num1, int num2){
            if(mp[num1]==mp[num2]){
                return num1<num2;
            }
            return mp[num1]<mp[num2];    // if true then return num1 else num2 
        };
        
        sort(arr1.begin(), arr1.end(), lambda);
        
        return arr1;
    }
};