class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<int>travelSumFromStartToIndex(travel.size());
        travelSumFromStartToIndex[0]=travel[0];
        for(int i=1; i<travel.size(); i++){
            travelSumFromStartToIndex[i]= travelSumFromStartToIndex[i-1]+ travel[i];
        }
      int countM=0, countP=0, countG=0, lastIndexM=0, lastIndexP=0, lastIndexG=0;
      int sum=0;
        
        for(int i=0; i<garbage.size(); i++){
            for(int j=0; j<garbage[i].size(); j++){
                if(garbage[i][j]=='M') {
                     lastIndexM =i;
                     countM++;
                }
                   
                else if(garbage[i][j]=='G'){
                     lastIndexG =i;
                    countG++;
                } 
                   
                else if(garbage[i][j]=='P'){
                     lastIndexP =i;
                    countP++;
                }     
            }
        }
        
        sum = sum + countM + countP + countG;  
        if(lastIndexM!=0){
            sum+= travelSumFromStartToIndex[lastIndexM-1];
        }
         if(lastIndexG!=0){
            sum+= travelSumFromStartToIndex[lastIndexG-1];
        }
         if(lastIndexP!=0){
            sum+= travelSumFromStartToIndex[lastIndexP-1];
        }
        return sum;
        
    }
};