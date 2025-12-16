class Solution {
public:
    void checkPalindrome(string s, int left, int right, int &start, int &maxLen){
        int count=0;
        while(left>=0 && right<s.length() && s[left]==s[right]){
           int len = right-left+1;
            if(len>maxLen){
               maxLen = len;
               start = left;
            }
            left--;
            right++;
        }
        return;
    }

    string longestPalindrome(string s) {
        int start=0, maxLen=0;
        for(int i=0; i<s.length(); i++){
           checkPalindrome(s, i, i, start, maxLen);   // odd case
           checkPalindrome(s, i, i+1, start, maxLen);   // even case
        }
        return s.substr(start, maxLen);
    }
};