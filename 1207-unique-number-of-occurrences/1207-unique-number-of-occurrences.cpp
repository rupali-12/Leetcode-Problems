class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Approach-1: Brute force 
        unordered_map<int, int>mp;
     for(auto a: arr){
         mp[a]++;
     }
        set<int>s;
        for(auto m: mp){
            s.insert(m.second);
        }
        return mp.size()==s.size();
    }
};



