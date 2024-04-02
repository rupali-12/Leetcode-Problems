class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        map<char, int>mps, mpt;
        for(int i=0; i<s.length(); i++){
            if(mps[s[i]]!=mpt[t[i]]) return false;
            mps[s[i]]= i+1;  // To handle cases like ab and aa
            mpt[t[i]]= i+1;
        }
        return true;
    }
};