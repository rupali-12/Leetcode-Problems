class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0, right=0, len=0;
        unordered_map<char, int>mp;
        int n=s.length();
        while(right<n){
            if(mp.find(s[right]) != mp.end()){
                left= max(left,  mp[s[right]]+1);   //  max use , bcoz dry run on "abba"
            }
            
            // update occurrence of char 
            mp[s[right]]= right;
            len= max(len, right-left+1);
            right++;
        }
        return len;
    }
};

