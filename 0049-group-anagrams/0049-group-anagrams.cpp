class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       // Approach-1: using freq 
        map<vector<int>, vector<string>>mp;
        for(int i=0; i<strs.size(); i++){
            vector<int>freq(26, 0);
            for(auto ch: strs[i]){
                freq[ch-'a']++;
            }
            mp[freq].push_back(strs[i]);
        }
        
        vector<vector<string>>ans;
        for(auto m: mp){
           ans.push_back(m.second);
        }
        return ans;
    }
};

