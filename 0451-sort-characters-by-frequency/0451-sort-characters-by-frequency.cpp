class Solution {
public:
   static bool cmp(const pair<char, int>a, const pair<char, int>b){
        return a.second > b.second;
    }
    string frequencySort(string s) {
        string ans="";
        map<char, int>mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        vector<std::pair<char, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), cmp);
        for(auto a:vec){
            int cnt= a.second;
            while(cnt--){
                ans+= a.first;
            }
        }
        return ans;
    }
};