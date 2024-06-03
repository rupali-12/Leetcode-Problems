class Solution {
public:
    int appendCharacters(string s, string t) {
        int ans=0;
        int i=0, j=0;
        while(i<s.length() && j<t.length()){
            if(s[i]==t[j]){
                i++; j++;
            }
            else{
                while(i<s.length() && s[i]!=t[j]){
                    i++;
                }
            }
             ans= t.length()-j;
        }
        
        return ans;
    }
};