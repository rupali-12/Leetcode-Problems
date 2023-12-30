class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int>mp;
        int n = words.size();
        if(n==1) return true;
        for(int i=0; i<n; i++){
           for(int j=0; j<words[i].length(); j++){
                mp[words[i][j]]++;
           }
        }
        for(auto a: mp){
            if(a.second%n){
                return false;
            }
        }
        return true;
    }
};