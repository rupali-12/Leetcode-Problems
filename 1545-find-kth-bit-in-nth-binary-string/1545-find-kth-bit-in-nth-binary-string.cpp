class Solution {
public:

    
    string nthString(int n){
        if(n==0) return "0";
        string s= nthString(n-1);
        string ans = s + "1";
        
        // invert s 
         for(int i=0; i<s.length(); i++){
            if(s[i]=='0'){
                s[i]='1';
            }
            else{
                s[i]='0';
            }
        }
        
        // reverse s 
       reverse(s.begin(), s.end()); 
        ans = ans + s;
        return ans;
    }
    
    char findKthBit(int n, int k) {
        string ans = nthString(n);
        return ans[k-1];
    }
};