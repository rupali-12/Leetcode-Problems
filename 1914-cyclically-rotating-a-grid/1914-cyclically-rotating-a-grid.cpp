class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m= grid.size();
        int n= grid[0].size();

        int layers = min(m, n)/2;

        for(int layer=0; layer<layers; layer++){
            vector<int>vec;

            int top= layer;
            int left=layer;
            int bottom = m-layer-1;
            int right = n-layer-1;

            // top layer
            for(int i=left; i<=right; i++){
               vec.push_back(grid[top][i]);
            }

            // right layer
            for(int i=top+1; i<=bottom-1; i++){
               vec.push_back(grid[i][right]);
            }

            // bottom layer
            for(int i=right; i>=left; i--){
               vec.push_back(grid[bottom][i]);
            }

            // left layer
            for(int i=bottom-1; i>=top+1; i--){
               vec.push_back(grid[i][left]);
            }

            int size = vec.size();

            int rotations = k%size;
            rotate(vec.begin(), vec.begin()+rotations, vec.end());
            
            // fill matrix after rotation 
            int idx= 0;
            // top layer
            for(int i=left; i<=right; i++){
              grid[top][i] = vec[idx++];
            }

            // right layer
            for(int i=top+1; i<=bottom-1; i++){
               grid[i][right] = vec[idx++];
            }

            // bottom layer
            for(int i=right; i>=left; i--){
               grid[bottom][i] = vec[idx++];
            }

            // left layer
            for(int i=bottom-1; i>=top+1; i--){
               grid[i][left] = vec[idx++];
            }
        }
        return grid;
    }
};