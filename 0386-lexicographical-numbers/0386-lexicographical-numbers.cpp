class Solution {
public:
    void solve(int start, int n, vector<int>&ans){
        if(start>n) return;
        ans.push_back(start);
       for(int append=0; append<=9; append++){
           int newNum= start*10 + append;
           if(newNum>n) return;
           solve(newNum, n, ans);
       }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int start=1; start<=9; start++){
            solve(start, n, ans);
        }
        
        return ans;
    }
};