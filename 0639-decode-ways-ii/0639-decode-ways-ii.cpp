class Solution {
public:
     long long mod= 1000000007;
    long long solveMem(string &s, int index, int len, vector<long long>&dp){
        long long ans=0, mul= 1;
        if(index==len) return 1;
        if(s[index]=='0') return 0;
        
        if(dp[index]!=-1) return dp[index];
        
        if(s[index]=='*'){
            mul=9;
        }
        
        ans+= mul*solveMem(s, index+1, len, dp);
        
        if(index<len-1){
            char next = s[index+1];
            int opt= 0;
            
            // case when s[index]='*'
            if(s[index]=='*'){
                if(next=='*'){
                    opt=15;
                }
                else{
                    if(next<='6'){
                        opt=2;
                    }
                    else{
                        opt=1;
                    }
                }
            }
            else if(s[index]<'3'){
                if(next=='*'){
                    if(s[index]=='1'){
                        opt=9;
                    }
                    else{
                        opt=6;
                    }
                }
                else{   // s[index]= num
                    if(s.substr(index, 2)<="26"){
                        opt=1;
                    }
                }
            }
            
            if(opt){
                ans+= opt*solveMem(s, index+2, len, dp);
            }
            
        }     // if end
        
        return dp[index]=ans%mod;
    }
    int numDecodings(string s) {
     int  len = s.length();
        vector<long long >dp(len+1, -1);
        return solveMem(s, 0, len, dp);
    }
};