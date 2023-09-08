class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows= matrix.size();
        int cols= matrix[0].size();
        vector<vector<int>>ans(cols, vector<int>(rows, 0));
        for(int i=0; i<cols; i++){
            for(int j= 0; j<rows; j++){
                ans[i][j]= matrix[j][i];
            }
        }
        return ans;
    }
};