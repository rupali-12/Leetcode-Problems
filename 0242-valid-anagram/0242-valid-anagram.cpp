class Solution {
public:
    bool isAnagram(string s, string t) {
        int n= s.length(), m=t.size();
        if(n!=m) return false;
        vector<int>sChar(26), tChar(26);
        
        for(int i=0; i<n; i++){
            sChar[s[i]-'a']++;
            tChar[t[i]-'a']++;
        }
        
        for(int i=0; i<26; i++){
            if(sChar[i]!=tChar[i]) return false;
        }
        return true;
    }
};