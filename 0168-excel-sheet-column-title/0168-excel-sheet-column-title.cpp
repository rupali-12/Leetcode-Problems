class Solution {
public:
    string convertToTitle(int n) {
        string ans="";
        while(n>0){
            if(n%26==0){
                ans+= 'Z';
                n--;
            }
            else{
                ans+= (n%26 -1) + 'A';
            }
            n/=26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};