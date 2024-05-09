typedef long long ll;
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ll sum=0;
        int i=1;
        priority_queue<int>pq;
        for(auto num: happiness){
            pq.push(num);
        }
      
        while(i<=k){
            int top = pq.top();
            if(top - (i-1) <0){
                top = 0;
            }
            else{
                top = top - (i-1);
            }
            pq.pop();
            sum+= top;
            i++;
        }
        return sum;
    }
};