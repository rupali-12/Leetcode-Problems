class Solution {
public:
    int numberOfSpecialChars(string word) {
          int n=word.length();
          vector<int>lastLower(26, -1);
          vector<int>firstUpper(26, INT_MAX);

          for(int i=0; i<n; i++){
            char ch =word[i];
            if(ch>='a' && ch<='z'){
                lastLower[ch-'a'] = i;
            }
            else{
                // store min or first index 
                firstUpper[ch-'A'] = min(firstUpper[ch-'A'], i);
            }
          }

        //   check all index
        int cnt=0;
        for(int i=0; i<26; i++){
            if(lastLower[i]!=-1 && firstUpper[i]!=INT_MAX && lastLower[i]<firstUpper[i]){
                cnt++;
            }
        }
        return cnt;
    }
};