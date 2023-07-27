#include <regex>
#include <string>

class Solution {
public:
    string reverseWords(string S) {
         S = std::regex_replace(S, std::regex("^\\s+|\\s+$"), "");
        string t="";
      bool lastCharSpace=false;
        for(int i=0; i<S.length(); i++){
            if(S[i]==' '){
                if(!lastCharSpace){
                    t.push_back(S[i]);
                    lastCharSpace=true;
                }
            }
            else{
               t.push_back(S[i]);
                    lastCharSpace=false;
            }
        }
        // cout<<"T=> "<<t<<" ";
        S=t;
          string ans="";
        string temp="";
        for(int i=S.length()-1; i>=0; i--){
            if(S[i]!=' '){
                temp.push_back(S[i]);
            }
            else{
                reverse(temp.begin(),temp.end());
                ans = ans+temp+" ";
                temp="";
                // count=0;
            }
        }
        // Handle last move 
         reverse(temp.begin(),temp.end());
        ans+= temp;
        return ans;
    }
};


