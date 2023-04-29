class Solution {
public:
    bool check(vector<int>&base, vector<int>&newPlacedBox){
        if(newPlacedBox[0]<= base[0] && newPlacedBox[1]<= base[1] && newPlacedBox[2]<= base[2]){
            return true;
        }
        return false;
    }
    int solve(vector<vector<int>>&cuboids){
        int n = cuboids.size();
        vector<int>currRow(n+1, 0);
        vector<int>nextRow(n+1, 0);
        for(int curr =n-1; curr>=0; curr--){
            for(int prev= curr-1; prev>=-1; prev--){
                // case of include
                int include=0;
                if(prev==-1 || check(cuboids[curr], cuboids[prev])){
                    include = cuboids[curr][2] + nextRow[curr+1];
                }
                
                int exclude = 0+ nextRow[prev+1];
                
                // store ans
                currRow[prev+1] = max(include, exclude);
            }
            // update next row
            nextRow =currRow;
        }
        return nextRow[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        // step-1>> sort all dimensions of all cuboids 
        for(auto &a: cuboids){
            sort(a.begin(), a.end());
        }
        
        // step-2>> sort all cuboids based on width 
        sort(cuboids.begin(), cuboids.end());
        
        // step-3> solve 
        return solve(cuboids);
    }
};