class Solution {
public:
    int longestPalindrome(string s) {
       int ans=0;
        unordered_map<char, int>mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        
        bool isOnePresent=0;
        for(auto m: mp){
            ans+= (m.second/2)*2;
            if(m.second%2==1) isOnePresent=true;
        }
        
       if(isOnePresent) ans++;
        return ans;
    }
};