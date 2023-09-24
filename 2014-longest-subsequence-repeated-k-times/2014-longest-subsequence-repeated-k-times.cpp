class Solution {
public:
   // check function to check given ans present k times in given string or not 
    bool check(string s, string ans, int k){
        int j=0, m= ans.size();
        for(int i=0; i<s.length(); i++){
            if(s[i]==ans[j]){
                j++;
            }
            if(j==m){
                k--;
                if(k==0) return true;
                j=0;
            }
        }
        return false;
    }
    
    // solve function to find longest valid subsequence by exploring characters from z to a 
    string solve(string s, string ans, int k){
        string curr="";
        int currLen=0;
        for(char ch='z'; ch>='a'; ch--){
            if(check(s, ans+ch, k)){
                ans+=ch;
                string temp = ch + solve(s, ans, k);
                if(currLen<temp.size()){
                    currLen=temp.size();
                   curr = temp;
                }
                ans.pop_back();    // To backtrack 
            }
        }
        return curr;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        string ans="";
        return solve(s, ans, k);
    }
};