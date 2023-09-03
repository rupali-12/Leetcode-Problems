class Solution {
public:
    int maxPower(string s) {
            int maxLen=1;
        int count=1;
        char ch=s[0];
        for(int i=1; i<s.length(); i++){
            if(s[i]==ch){
                count++;
                 maxLen= max(maxLen, count);
            }
            else{
                maxLen= max(maxLen, count);
                ch= s[i];
                count=1;
            }
        }
        return maxLen;
    }
};