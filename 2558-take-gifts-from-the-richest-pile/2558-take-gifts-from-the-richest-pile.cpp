class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int,vector<int>>pq;
        for(auto num: gifts){
            pq.push(num);
        }
        
        while(k--){
          int top= pq.top();
          pq.pop();
            pq.push(sqrt(top));
        }
        
        long long sum=0;
        while(!pq.empty()){
            sum+= pq.top();
            pq.pop();
        }
        return sum;
    }
};