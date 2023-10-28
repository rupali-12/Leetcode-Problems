class Solution {
public:
    int mod = 1e9+7;
    int solveRec(int n, int i, char prev, vector<vector<long long>>&dp, unordered_map<char, vector<char>>&mp){
        if(i>n){
            return 0;
        }
        if(i==n){
            switch(prev){
                case 'a': 
                    return 1;
                case 'e': 
                    return 2;
                case 'i': 
                    return 4;
                case 'o': 
                    return 2;
                case 'u': 
                    return 1;
                default: return 5;   // case of n=1 (prev=='c')
            }
        }
        
        int idxOfPrev = prev-'a';
        if(dp[i][idxOfPrev]!=-1){
            return dp[i][idxOfPrev];
        }
        
        long long ans=0;
        for(auto next: mp[prev]){
            ans+= solveRec(n, i+1, next, dp, mp);
            ans= ans%mod;
        }
      return dp[i][idxOfPrev] = ans%mod;
    }
    int countVowelPermutation(int n) {
        int i=1;
        // map >
        unordered_map<char, vector<char>>mp;
        char prev='c';  // let as it cannot in permutation
        mp['c']={'a', 'e', 'i', 'o', 'u'};
        mp['a']={'e'};
        mp['e']={'a', 'i'};
        mp['i']={'a', 'e', 'o','u'};
        mp['o']={'i', 'u'};
        mp['u']={'a'};
        
        vector<vector<long long>>dp(n+1, vector<long long>(26, -1));  // 27 a bcoz i need to find ascii of vowel 
        return solveRec(n, i, 'c', dp, mp);
    }
};