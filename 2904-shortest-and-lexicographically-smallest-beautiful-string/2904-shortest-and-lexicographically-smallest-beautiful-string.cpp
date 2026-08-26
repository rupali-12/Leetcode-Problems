class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans="";
        int i=0, j=0;
        int count1=0;
        while(j<s.length()){
            if(s[j]=='1') count1++;
            while(count1 >k || s[i]=='0'){
                if(s[i]=='1') count1--;
                i++;
            }
            if(count1==k){
                string temp = s.substr(i, j-i+1);
                if(ans.empty() || (temp.length() < ans.length()) || 
                (temp.length() == ans.length() && temp < ans)){
                    ans = temp;
                }
            }
            j++;
        }
        return ans;
    }
};