class Solution {
public:
    vector<string>ans;
    vector<string> createGrid(int m, int n) {
        for(int i=0; i<m; i++){
            string str="";
            for(int j=0; j<n; j++){
                if(i==0 || j==n-1) str+= '.';
                else str+= '#';
            }
            ans.push_back(str);
        }
        return ans;
    }
};