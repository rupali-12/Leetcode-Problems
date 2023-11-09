class Solution {
public:
    int countHomogenous(string s) {
        int mod= 1e9 +7;
        vector<int>len(s.length(), 0);
        len[0]=1;
        for(int i=1; i<s.length(); i++){
            len[i]=1;
            if(s[i]==s[i-1]){
                len[i]+= len[i-1];
            }
        }
         
        // sum of elements of len vector 
        int sum=0;
        for(auto a: len){
            sum+= a;
            sum= sum%mod;
        }
        return sum;
    }
};