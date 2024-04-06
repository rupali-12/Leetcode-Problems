class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
//         // Approach-1: Using Stack 
//         int n= s.length();
//         stack<int>st;
//         unordered_set<int>removed_idx;
        
//         for(int i=0; i<n; i++){
//            if(s[i]=='('){
//                st.push(i);
//            }    
//             else if(s[i]==')'){
//                 if(st.empty()){
//                     removed_idx.insert(i);
//                 }
//                 else{
//                     st.pop();
//                 }
//             }
//         }
        
//         while(!st.empty()){
//             removed_idx.insert(st.top());
//             st.pop();
//         }
//        string ans="";
//         for(int i=0; i<n; i++){
//             if(removed_idx.find(i)==removed_idx.end()){
//                 ans+= s[i];
//             }
//         }
//         return ans;
        
         // Approach-2: Without Using Stack 
        int n= s.length();
        int open=0, close=0;
        string ans="";
        // forward traversing to remove unbalanced closed parentheses 
        for(int i=0; i<n; i++){
           if(s[i]>='a' && s[i]<='z'){
               ans+= s[i];
           }    
            else if(s[i]=='('){
                open++;
                ans+= s[i];
            }
            else if(open>0){
                open--;
                ans+= s[i];
            }
        }
        
        // backward traversing to remove unbalanced open parentheses 
        string final_ans="";
          for(int i=ans.length()-1; i>=0; i--){
           if(ans[i]>='a' && ans[i]<='z'){
               final_ans+= ans[i];
           }    
            else if(ans[i]==')'){
                close++;
                final_ans+= ans[i];
            }
            else if(close>0){
                close--;
                final_ans+= ans[i];
            }
        }
        reverse(final_ans.begin(), final_ans.end());
        return final_ans;
    }
};