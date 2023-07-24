class Solution {
public:
    bool isNumber(string s) {
      bool pointPresent = false;
      bool ePresent = false;
      bool numPresent =false;
    bool numAfterEPresent= true;
        for(int i=0; i<s.length(); i++){
            if(s[i]>='0' && s[i]<='9'){
                numPresent=true;
                numAfterEPresent=true;
            }
            else if(s[i]=='.'){
                if(ePresent || pointPresent){
                    return false;
                }
                pointPresent= true;
            }
             else if(s[i]=='e' || s[i]=='E'){
                if(ePresent || !numPresent){
                    return false;
                }
                 numAfterEPresent=false;  // to check if number is present ater e or not
                ePresent= true;
                 
            }
             else if(s[i]=='-' || s[i]=='+'){
                if(i!=0 && s[i-1]!='e' && s[i-1]!='E'){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return numPresent && numAfterEPresent;
    }
};