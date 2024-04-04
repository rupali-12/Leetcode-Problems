class Solution {
public:
    int maxDepth(string s) {
        
        // // Approach-1: With space complexity
        // stack<char>st;
        // int max_depth= 0;
        // for(int i=0; i<s.length(); i++){
        //     if(s[i]=='('){
        //         st.push(s[i]);
        //     }
        //     else if(s[i]==')'){
        //         st.pop();
        //     }
        //     max_depth= max(max_depth, (int)st.size());
        // }
        // return max_depth;
        
        // Approach-2: Without space complexity
        int max_depth= 0, depth=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                depth++;
            }
            else if(s[i]==')'){
               depth--;
            }
            max_depth= max(max_depth, depth);
        }
        return max_depth;
    }
};