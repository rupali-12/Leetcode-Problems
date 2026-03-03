class Solution {
public:
    string findNthStr(int n){
       if(n==1) return "0";
       string s = findNthStr(n-1);
       string ans = s + '1';

    //    invert s 
    for(int i=0; i<s.length(); i++){
        if(s[i]=='1') s[i] = '0';
        else s[i] ='1';
    }

    // reverse s
    reverse(s.begin(), s.end());
    ans = ans+s;
    return ans;
    }
    char findKthBit(int n, int k) {
        string ans = findNthStr(n);
        return ans[k-1];
    }
};


