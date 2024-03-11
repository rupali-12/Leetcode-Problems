class Solution {
public:
    bool rowColMatch(vector<int>row, vector<int>col, int n){
        for(int i=0; i<n; i++){
            if(row[i]!=col[i]){
                return false;
            }
        }
        return true;
    }
    
    int equalPairs(vector<vector<int>>& grid) {
        int n= grid.size();
        int ans=0;
        vector<vector<int>>transpose(n, vector<int>(n));
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
               transpose[r][c] = grid[c][r];
            }
        }
                for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                     if(rowColMatch(grid[r], transpose[c], n)){
                    ans++;
                }
            }
        
        }
       
        return ans;
    }
};