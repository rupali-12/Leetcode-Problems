class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int>s;
        vector<string>ans;
     int i=0;
        for(int j=1; j<=n; j++){
           if(i>=target.size()) break;
        
                if(target[i]==j){
                    ans.push_back("Push");
                    i++;
                }
                else{
                    ans.push_back("Push");
                    ans.push_back("Pop");
                }
        }
        return ans;
    }
};