class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, string>mp;
        for(auto s: paths){
           mp[s[0]]= s[1];    
        }

        auto start = paths[0][0];
        while(mp.find(start)!=mp.end()){
            start= mp[start];
        }
        return start;
    }
};