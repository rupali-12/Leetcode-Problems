class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        if(s.length()==2 && s[0]==s[1]) return 0;
        int ans=-1; 
       vector<int>count(26, -1);
        for(int i=0; i<s.length(); i++){
            if(count[s[i]-'a']==-1){
                count[s[i]-'a'] =i;
            }
            int temp= i- count[s[i]-'a']-1;
            ans= max(ans, temp);
        }
        return ans;
    }
};