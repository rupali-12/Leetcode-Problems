class Solution {
public:
    void solve(int open, int close,  vector<string>&ans, string output){
        if(open==0 && close==0){
            ans.push_back(output);
            return;
        }
        
        if(open!=0){
            string op1 =output;
            op1.push_back('(');
            solve(open-1, close, ans, op1);
        }
        if(close>open){
             string op2 =output;
            op2.push_back(')');
            solve(open, close-1, ans, op2);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string output="";
        int open=n, close=n;
        solve(open, close, ans, output);
        return ans;
    }
};