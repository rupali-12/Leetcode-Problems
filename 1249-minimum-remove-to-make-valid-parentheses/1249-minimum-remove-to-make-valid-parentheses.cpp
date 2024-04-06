class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        // Approach-1: Using Stack 
        int n= s.length();
        stack<int>st;
        unordered_set<int>removed_idx;
        
        for(int i=0; i<n; i++){
           if(s[i]=='('){
               st.push(i);
           }    
            else if(s[i]==')'){
                if(st.empty()){
                    removed_idx.insert(i);
                }
                else{
                    st.pop();
                }
            }
        }
        
        while(!st.empty()){
            removed_idx.insert(st.top());
            st.pop();
        }
       string ans="";
        for(int i=0; i<n; i++){
            if(removed_idx.find(i)==removed_idx.end()){
                ans+= s[i];
            }
        }
        return ans;
    }
};