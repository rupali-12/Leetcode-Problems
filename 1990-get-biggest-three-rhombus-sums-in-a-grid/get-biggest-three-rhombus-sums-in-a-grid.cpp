class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // Approach 1: Brute force
        set<int>st;

       auto addSet = [&](int sum){
        st.insert(sum);
        if(st.size()>3){
            st.erase(begin(st));   //erase from begin to remove smallest element 
        }
       };

        for(int r= 0; r<m; r++){
            for(int c=0; c<n; c++){
                // 2 side rhombus 
                addSet(grid[r][c]);

                for(int side =1; r-side>=0 && r+side<m && c-side>=0 && c+side<n; side++){
                    int sum =0;
                    for(int k=0; k<=side-1; k++){
                       sum+= grid[r-side+k][c+k];   // top to right vertices
                       sum+= grid[r+k][c+side-k];   // right to bottom vertices
                       sum+=  grid[r+side-k][c-k];    // bottom to left vertices
                       sum+= grid[r-k][c-side+k];   // left to top vertices
                    }
                    addSet(sum);
                }
            }
        }
        // vector<int>ans;
        // while(!st.empty()){
        //     ans.push_back(st.top());
        //     st.pop();
        // }
        // return ans;

        // set= {2, 5, 7}
        return vector<int>(rbegin(st), rend(st));  // {7, 5, 2}
    }
};


