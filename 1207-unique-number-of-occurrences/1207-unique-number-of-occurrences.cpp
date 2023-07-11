class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
     // Approach-1> using map and set 
        unordered_map<int, int>mp;
        for(auto i: arr){
            mp[i]++;
        }
        set<int>s;
        for(auto a: mp){
            s.insert(a.second);
        }
        return mp.size()==s.size();
    }
};



