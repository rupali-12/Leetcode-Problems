class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        map<char, vector<int>>mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]].push_back(i);
        }
        
        for(auto m: mp){
            char ch= m.first;
            vector<int>v = m.second;
            int numChars = v[1]-v[0]-1;
            if(distance[ch-'a']!=numChars){
                return false;
            }
        }
        return true;
    }
};