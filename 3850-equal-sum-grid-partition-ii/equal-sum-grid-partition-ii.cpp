class Solution {
public:
typedef long long ll;
ll totalSum=0;

bool checkHorCuts(vector<vector<int>>grid){
    int m=grid.size(), n=grid[0].size();
    ll top=0;

    unordered_set<ll>st;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            st.insert(grid[i][j]);
            top+= grid[i][j];
        }
        ll bottom=totalSum -top;
        ll diff= top-bottom;

        if(diff==0)return true;
        if(diff == grid[0][0]) return true;
        if(diff == grid[0][n-1]) return true;
        if(diff == grid[i][0]) return true;
        if(i>0 && n>1 && st.count(diff)!=0) return true;
    }
    return false;
}
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                totalSum+= grid[i][j];
            }
        }

        if(checkHorCuts(grid)){
            return true;
        }

        reverse(grid.begin(), grid.end());

         if(checkHorCuts(grid)){
            return true;
        }

        reverse(grid.begin(), grid.end());   // make grid to original so we can transpose original grid

        //  Vertical cut checking by using checkHorCuts method
    //    Transpose of grid and then do check checkHorCuts to check vertical cuts
    vector<vector<int>>transposeGrid(n, vector<int>(m));  // n*m
     for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            transposeGrid[j][i] = grid[i][j];
        }
     }

     if(checkHorCuts(transposeGrid)){
        return true;
     }

     reverse(transposeGrid.begin(), transposeGrid.end());

     if(checkHorCuts(transposeGrid)){
        return true;
     }
     
     return false;

    }
};