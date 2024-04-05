class Solution {
public:
    string makeGood(string s) {
        
        // // Approach-1: With stack 
        // int n= s.length();
        // stack<char>st;
        // for(int i=0; i<s.length(); i++){
        //     if(!st.empty() && ((st.top()-32)==s[i] || (st.top()+32)==s[i])){
        //         st.pop();
        //     }
        //     else{
        //       st.push(s[i]);    
        //     }
        // }
        // string ans="";
        // while(!st.empty()){
        //     ans+= st.top();
        //     st.pop();
        // }
        // reverse(ans.begin(), ans.end());
        // return ans;
        
        // Approach-2: Without stack
        string ans="";
        for(char &ch: s){
            if(!ans.empty() && (ans.back()-32==ch || ans.back()+32 == ch)){
                ans.pop_back();
            }
            else{
                ans.push_back(ch);
            }
        }
        return ans;
    }
};