class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxAns=0;
        map<char, int>mp;
        int i=0, j=0;
        while(j<s.length()){
            // if present in map then shrink 
            while(i<=j && (mp.find(s[j])!=mp.end())){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            mp[s[j]]++;
            maxAns= max(maxAns, (int)mp.size());
            j++;
        }
        return maxAns;
    }
};