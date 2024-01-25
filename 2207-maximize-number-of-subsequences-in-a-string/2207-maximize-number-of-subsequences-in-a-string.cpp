class Solution {
public:
    long long solve(string text, string pattern){
       long long ans=0;
        unordered_map<char, long long>mp;
        for(auto a: text){
            if(a==pattern[1]){
                ans+= mp[pattern[0]];
            }
            mp[a]++;
        }
        return ans;
    }
    
    long long maximumSubsequenceCount(string text, string pattern) {
       long long firstcharans = solve(pattern[0]+text, pattern);
        long long secondcharans = solve(text + pattern[1], pattern);
        return max(firstcharans, secondcharans);
    }
};