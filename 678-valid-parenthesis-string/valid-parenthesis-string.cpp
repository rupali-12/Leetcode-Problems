class Solution {
public:
    bool checkValidString(string s) {
        stack<char>star, open;
        int n= s.length();
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                open.push(i);
            }
            else if(s[i]=='*'){
                star.push(i);
            }
            else{
                if(!open.empty()){
                    open.pop();
                }
                else if(!star.empty()){
                    star.pop();
                }
                else{
                    return false;
                }
            }
        }
        
        // Now process left open bracket 
     while(!open.empty()){
         if(star.empty()) return false;
         else if(open.top() < star.top()){   // case when * -> ')'
             open.pop();
             star.pop();
         }
         else{
             return false;
         }
     }
        return true;
    }
};