class Solution {
public:
    int countOdds(int low, int high) {
        int count=0;
    
        // 1st approach using for loop >>>>>>>>>>>>>>>>>
        // for(int i=low; i<=high; i++){
        //     if(i%2!=0){
        //         count++;
        //     }
        // }
        
        
        // 2nd approach >>>>>>>>>>>>>
       //   int h = ceil(high/2);
       //  int l= ceil(low/2);
       // if(high%2==0){
       //     count = h-l;
       // }
       //  else{
       //      count= h-l+1;
       //  }
        
        // 3rd approach >>>>>>>>>>>>>>>>>>>
        count = (high+1)/2 - low/2;
        return count;
    }
};