class Solution {
public:
    int minimumLength(string s) {
        int len = s.length();
        int i=0, j= len-1;
        int ans=0;
        while(i<j && s[i]==s[j]){
                while(s[j]==s[j-1] && j>i+1){
                        j--;
                }
                 while(s[i]==s[i+1] && i<j-1){
                        i++;
                }
            i++; j--;
        }
          ans = j-i+1;
        return ans;
    }
};