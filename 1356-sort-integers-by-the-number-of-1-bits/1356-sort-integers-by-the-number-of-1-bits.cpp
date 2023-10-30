class Solution {
public:
    int countOne(int num){
        int count=0;
        while(num>0){
            if(num&1){
                count++;
            }
            num= num>>1;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<int>ans;
        // <count, elements >
        map<int, vector<int>>mp;
        for(int i=0; i<arr.size(); i++){
            int count = countOne(arr[i]);
            mp[count].push_back(arr[i]);
            
        }
        
        for(auto v: mp){
            sort(v.second.begin(), v.second.end());
            ans.insert(ans.end(), v.second.begin(), v.second.end());
        }
        return ans;
    }
};