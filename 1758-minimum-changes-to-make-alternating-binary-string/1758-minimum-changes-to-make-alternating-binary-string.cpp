class Solution {
public:
    int solve(string &s, char startChar){
        int ans=0;
       for(int i=0; i<s.length(); i++){
           if(i%2==0){
               if(s[i]!=startChar) ans++;
           }
           else{
               if(s[i]==startChar) ans++;
           }
       }
        return ans;
    }
    int minOperations(string s) {
        int maxCount=0;
        
       int ans0 = solve(s, '0');
       int ans1 = solve(s, '1');
        maxCount = min(ans0, ans1);
        return maxCount;
    }
};