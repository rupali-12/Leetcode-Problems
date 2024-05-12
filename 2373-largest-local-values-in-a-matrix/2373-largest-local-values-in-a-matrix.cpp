
class Solution {
public:
    int n;
    
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));
        
        for(int i = 1; i < n - 1; i++) {
            for(int j = 1; j < n - 1; j++) {
                int temp=0;
                
                for(int r = i-1; r<=i+1; r++){
                    for(int c=j-1; c<=j+1; c++){
                       temp = max(temp, grid[r][c]);        
                    }
                }
                
                ans[i-1][j-1] = temp;
            }
        }
        
        return ans;
    }
};
