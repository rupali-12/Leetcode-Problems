class Solution {
public:
    int getRowSum(vector<int>row){
        int sum=0;
        for(int i=0; i<row.size(); i++){
            sum+= row[i];
        }
        return sum;
    }
    int getColIndexOfOne(vector<int>row){
        for(int i=0; i<row.size(); i++){
            if(row[i]==1){
                return i;
            }
        }
        return -1;
    }
    int getColSum(vector<vector<int>>& mat, int colIndex){
        int sum=0;
        for(auto row: mat){
             sum+= row[colIndex];
        }
        return sum;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int ans=0;
        for(auto row: mat){
            if(getRowSum(row)==1){  // if sum=1 then process only
                int colIndex = getColIndexOfOne(row);
                ans+= (getColSum(mat, colIndex)==1)?1:0;
            }
        }
        return ans;
    }
    
};