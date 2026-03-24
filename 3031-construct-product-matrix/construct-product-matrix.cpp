class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m= grid.size(), n=grid[0].size();
        int mod =12345;
        vector<vector<int>>p(m, vector<int>(n));  // result = product matrix

        long long suffix = 1;
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                p[i][j]=suffix;
                suffix = (suffix*grid[i][j])%mod;
            }
        }

        long long prefix = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                p[i][j] = (prefix*p[i][j])%mod;
                prefix = (prefix*grid[i][j])%mod;
            }
        }
        return p;
    }
};