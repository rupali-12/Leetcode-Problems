class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string temp="";
        int i=0, n= s.length();
        while(i<n){
            while(i<n && s[i]==' ') i++;
            while(i<n && s[i]!=' '){
                temp+= s[i];
                i++;
            }
            
            if(temp.size()>0){
                if(ans.size()==0){
                    ans=temp;
                }
                else{
                    ans = temp+" "+ans;
                }
                temp="";
            }
        }
        return ans;
    }
};