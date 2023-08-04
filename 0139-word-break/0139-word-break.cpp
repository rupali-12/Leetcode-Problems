class Solution {
public:
    int dp[300];
    bool solve(int i, string &s, set<string>& wordDict){
        if(i==s.size()){
            return 1;
        }
        string temp;
        if(dp[i]!=-1){
            return dp[i];
        }
        for(int j=i; j<s.size(); j++){
            temp+= s[j];
            if(wordDict.find(temp)!=wordDict.end()){
                if(solve(j+1, s, wordDict)){
                    return dp[i]=1;
                }
            }
        }
        return dp[i]= 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
       set<string>word;
        for(auto a: wordDict){
            word.insert(a);
        }
        memset(dp, -1, sizeof dp);
       return solve(0, s, word);
    }
};