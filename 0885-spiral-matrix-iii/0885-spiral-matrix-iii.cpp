class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
//         E, S, W, N
        vector<vector<int>>directions = {{0, 1}, {1,0}, {0, -1}, {-1,0}};
         vector<vector<int>>results;
        
        int steps=0;
        int dir = 0;   // intiallly taking east, 1-> S, 2-> W, 3-> N
        
        
        // push starting location 
        results.push_back({rStart, cStart});
        
        while(results.size() < (rows* cols)){
            if(dir==0 || dir==2){  // id west or east 
                steps++;
            }
            
            for(int count=0; count<steps; count++){
                rStart+= directions[dir][0];
                cStart+= directions[dir][1];
                
                if(rStart>=0 && rStart< rows && cStart>=0 && cStart<cols){   // valid cell
                    results.push_back({rStart, cStart});
                }
            }
            
            // update dir 
            dir= (dir+1)%4;
        }
        return results;
    }
};