class Solution {
public:
    int countOdds(int low, int high) {
        int count=0;
    
        // for(int i=low; i<=high; i++){
        //     if(i%2!=0){
        //         count++;
        //     }
        // }
        
        
         int h = ceil(high/2);
        int l= ceil(low/2);
       if(high%2==0){
           count = h-l;
       }
        else{
            count= h-l+1;
        }
        return count;
    }
};