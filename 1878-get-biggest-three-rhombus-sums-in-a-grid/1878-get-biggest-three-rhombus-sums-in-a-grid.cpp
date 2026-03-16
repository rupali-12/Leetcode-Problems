class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int>st;

       auto addSet = [&](int sum){
        st.insert(sum);
        if(st.size()>3){
            st.erase(begin(st));   //erase from begin to remove smallest element 
        }
       };

       //  Towards right diagonal 
                vector<vector<int>>d1(m, vector<int>(n, 0));
                for(int i=0; i<m; i++){
                    for(int j=0; j<n; j++){
                        d1[i][j]+= grid[i][j];
                        if(i-1>=0 && j-1>=0){
                            d1[i][j]+= d1[i-1][j-1];
                        }
                    }
                }
            
            //  Towards left diagonal 
                vector<vector<int>>d2(m, vector<int>(n, 0));
             for(int i=0; i<m; i++){
                    for(int j=0; j<n; j++){
                        d2[i][j]+= grid[i][j];
                        if(i-1>=0 && j+1<n){
                            d2[i][j]+= d2[i-1][j+1];
                        }
                    }
                }

        for(int r= 0; r<m; r++){
            for(int c=0; c<n; c++){
                // 2 side rhombus 
                addSet(grid[r][c]);
               
                for(int side =1; r-side>=0 && r+side<m && c-side>=0 && c+side<n; side++){
                    int sum =0;

                    // // Approach 1: Brute force  TC= O(m*n*(side)^2)  SC = O(1)
                    // for(int k=0; k<=side-1; k++){
                    //    sum+= grid[r-side+k][c+k];   // top to right vertices
                    //    sum+= grid[r+k][c+side-k];   // right to bottom vertices
                    //    sum+=  grid[r+side-k][c-k];    // bottom to left vertices
                    //    sum+= grid[r-k][c-side+k];   // left to top vertices
                    // }

                    // Approach -2: Sum using stored right & left diagonal sum 
                    int top_r = r-side, top_c = c;   // top vertex
                    int right_r = r, right_c = c+side;   // top vertex
                    int bottom_r = r+side, bottom_c = c;   // top vertex
                    int left_r= r, left_c = c-side;   // top vertex
                    
                    // Sum from top vertex to right vertex
                    // require subtracting the previous diagonal cell, not the vertex itself.
                    sum+= d1[right_r][right_c];
                    if(top_r - 1>=0 && top_c-1>=0){
                        sum-= d1[top_r-1][top_c-1];
                    }

                    // Sum from right vertex to bottom vertex
                    sum+= d2[bottom_r][bottom_c];
                    if(right_r-1>=0 && right_c+1<n){
                     sum-=  d2[right_r-1][right_c+1];
                    }

                    // Sum from bottom vertex to left vertex
                    sum+= d1[bottom_r][bottom_c];
                    if(left_r-1>=0 && left_c-1>=0){
                        sum-= d1[left_r-1][left_c-1];
                    }

                    // Sum from left vertex to top vertex
                    sum+= d2[left_r][left_c];
                    if(top_r-1>=0 && top_c+1<n){
                        sum-=d2[top_r-1][top_c+1];
                    }

         // Here vertices added twice, so remove duplicates .
         sum-= grid[top_r][top_c];
         sum-= grid[right_r][right_c];
         sum-= grid[bottom_r][bottom_c];
         sum-= grid[left_r][left_c];
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


