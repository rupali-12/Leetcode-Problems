class Solution {
public:
    int numberOfSpecialChars(string word) {
       unordered_set<char>lower, upper;
       int n=word.length(), cnt=0;
       for(int i=0; i<n; i++){
          if(word[i]>='a' && word[i]<='z'){
           lower.insert(word[i]);
          }
          else{
            upper.insert(word[i]);
          }
       }
       for(auto m:lower){
        if(upper.count(m-32)){
            cnt++;
        }
       }
       return cnt;  
    }
};