class Solution {
public:
    bool solve(int index, int i, int j, string word, vector<vector<char>>& b){
        if(index==word.size()){
            return true;
        }
        if(i<0 || j<0 || i== b.size() || j==b[0].size()){
            return false;
        }
        
        bool ans= false;
        if(word[index]== b[i][j]){
            b[i][j]='*';
            
            ans= solve(index+1, i-1, j, word, b) || solve(index+1, i+1, j, word, b) || solve(index+1, i, j-1, word, b) || solve(index+1, i, j+1, word, b);
            
            b[i][j]=word[index];
        }
        return ans;
    }
    bool exist(vector<vector<char>>& b, string word) {
         int m= b.size();
        int n= b[0].size();
       int k=0;
        bool ans=false;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(word[k]==b[i][j]){
                    if(solve(k, i, j, word, b)){
                        return true;
                    }
                }
            }
        }
        return ans;
    }
};