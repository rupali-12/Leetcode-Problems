class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // approach -1: using stack
        int n=s.length();
        unordered_set<int>removedIdx;
        stack<int>st;

        for(int i=0; i<n; i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(st.empty()){
                    removedIdx.insert(i);
                }
                else{
                    st.pop();
                }
            }
        }

        // place in removedIdx if any extra open brackets present in st
        while(!st.empty()){
            removedIdx.insert(st.top());
            st.pop();
        }

        string ans="";
        for(int i=0; i<n; i++){
           if(removedIdx.find(i)==removedIdx.end()){
            ans+=s[i];
           }
        }
       return ans;
    }
};