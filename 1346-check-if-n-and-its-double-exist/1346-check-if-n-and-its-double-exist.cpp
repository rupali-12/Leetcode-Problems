class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n= arr.size();
        
        map<int, int>mp;
        for(int i=0; i<n; i++){
            if((mp.find(arr[i]*2)!=mp.end()) || (arr[i]%2==0 && mp.find(arr[i]/2)!=mp.end())){
                return true;
            }
            mp[arr[i]]++;
        }
        return false;
    }
};