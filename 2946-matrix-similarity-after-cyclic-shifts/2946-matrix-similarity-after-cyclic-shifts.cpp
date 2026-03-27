class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size(), n=mat[0].size();

    //     // Approach-1: Brute approach
    //     vector<vector<int>>temp = mat;
    //   while(k--){
    //      for(int i=0; i<m; i++){
    //         int first = mat[i][0];
    //     //   for even row, shift left
    //        if(i%2==0){
    //          for(int j=0; j<n-1; j++){
    //            mat[i][j]= mat[i][j+1];
    //         }

    //         // Now fill end column position
    //         mat[i][n-1] = first;
    //        }
    //     else{
    //         int last = mat[i][n-1];
    //     //   for even row, shift right
    //          for(int j=n-1; j>0; j--){
    //            mat[i][j]= mat[i][j-1];
    //         }

    //         // Now fill first column position
    //         mat[i][0] = last;
    //        }
    //     }
    //   }
 
    //     return temp==mat;

    // Approach-2: Optimize
    k=k%n;
    for(int i=0;i<m; i++){
        for(int j=0; j<n; j++){
            int newCol;
            if(i%2==0){
                newCol = (j+k)%n;
            }
            else{
                newCol= (j-k+n)%n;
            }

            if(mat[i][j]!=mat[i][newCol]){
                return false;
            }
        }
    }
    return true;
    }
};

