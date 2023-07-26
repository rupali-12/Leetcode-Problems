class Solution {
public:
    void solve(string digits,  vector<string>&ans, string output, int index, string mapp[]){
        if(index==digits.length()){
            ans.push_back(output);
            return;
        }
        
        int num = digits[index]-'0';
        string val = mapp[num];
        
        for(int i=0 ;i<val.length(); i++){
            output.push_back(val[i]);
            solve(digits, ans, output, index+1, mapp);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
        vector<string>ans;
        string output="";
        int index=0;
        if(digits==""){
            return ans;
        }
        string mapp[10]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, ans, output, index, mapp);
        return ans;
    }
};

