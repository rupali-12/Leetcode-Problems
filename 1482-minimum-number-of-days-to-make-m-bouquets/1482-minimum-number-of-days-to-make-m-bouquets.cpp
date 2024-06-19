class Solution {
public:
    
    int canMakeBloom(vector<int>&bloomDay, int mid, int k){
        int bouquetCount=0, cons_count=0;
        
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i]<=mid){
                cons_count++;
            }
            else{
                cons_count=0;
            }
            
            if(cons_count==k){
                bouquetCount++;
                cons_count=0;
            }
        }
        return bouquetCount;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n= bloomDay.size();
        int minDays=-1;
        int startDay=0, endDay= *max_element(begin(bloomDay), end(bloomDay));
        
        while(startDay<= endDay){
            int mid = startDay+ (endDay-startDay)/2;
            if(canMakeBloom(bloomDay, mid, k)>=m){
                minDays= mid;
                endDay = mid-1;
            }
            else{
                startDay = mid+1;
            }
        }
        return minDays;
    }
};