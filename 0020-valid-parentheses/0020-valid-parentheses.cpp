class Solution {
public:
    bool isValid(string s) {
        string temp;
        if(s.length()%2!=0){
            return false;
        }
        for(int i=0; i<s.length(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                temp.push_back(s[i]);
            }
            else{
                if((s[i]==')' && temp.back()!='(') || (s[i]=='}' && temp.back()!='{') || (s[i]==']' && temp.back()!='[')){
                  return false;
                }
                  temp.pop_back();
            }
        }
        if(temp.size()==0){
            return true;
        }
        return false;
    }
};