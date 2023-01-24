class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col= matrix[0].size();
        int row= matrix.size();
        bool temp= false;
            int s=0, e = row*col-1;
            while(s<=e){
                int mid = s +(e-s)/2;
                int temp= matrix[mid/col][mid%col];
                if(temp==target){
                 return true;
                }
                else if(temp<target){
                    s = mid+1;
                }
                else{
                    e = mid-1;
                }
            }
        return false;
    }
};