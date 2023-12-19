class Solution {
public:
    int findAvg(vector<vector<int>>& img, int x, int y){
         int row= img.size(), col= img[0].size();
        int sum=img[x][y];
        int countElement=1;   // count=1 as img[x][y] always included 
        // up 
        if(x>0){
            sum+= img[x-1][y];
            countElement++;
        }
            
        
        // down
        if(x<row-1){ 
            sum+= img[x+1][y];
            countElement++;}
        
        // left 
        if(y>0){
            sum+= img[x][y-1];
             countElement++;}
        
        // right
        if(y<col-1){ 
            sum+= img[x][y+1];
             countElement++;}
        
        // upper left diagonal 
        if(x>0 && y>0){  
            sum+= img[x-1][y-1];
            countElement++;}
        
        // upper right diagonal 
        if(x>0 && y<col-1){  
            sum+= img[x-1][y+1];
            countElement++;}
        
        // lower left diagonal 
        if(x<row-1 && y>0){ 
            sum+= img[x+1][y-1];
            countElement++;}
        
        // lower right diagonal 
        if(x<row-1 && y<col-1){
             sum+= img[x+1][y+1];
            countElement++;}
        
        int avgAns = sum/ countElement;
        return avgAns;
        
    }
    
    

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int row= img.size(), col= img[0].size();
        vector<vector<int>>ans(row, vector<int>(col, 0));
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                int avg = findAvg(img, i, j);
                ans[i][j] = avg;
            }
        }
        return ans;
    }
};