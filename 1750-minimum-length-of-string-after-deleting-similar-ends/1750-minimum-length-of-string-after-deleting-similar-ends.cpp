class Solution {
public:
    int minimumLength(string s) {
        int len = s.length();
        int i=0, j= len-1;
        int ans=0;

        for(; i<j && s[i]==s[j]; i++, j--){
             while(s[j]==s[j-1] && j>i+1){
                        j--;
                }
                 while(s[i]==s[i+1] && i<j-1){
                        i++;
                }
        }
          ans = j-i+1;
        return ans;
    }
};