class Solution {
public:
    typedef pair<int, int> P;
    long long findScore(vector<int>& nums) {
        long long score=0;
        priority_queue<P, vector<P>, greater<P>>pq;
        for(int i=0; i<nums.size(); i++){
            pq.push({nums[i], i});
        }
        
        vector<bool>isMarked(nums.size(), false);
        while(!pq.empty()){
            int value = pq.top().first;
            int idx= pq.top().second;
            pq.pop();
            if(!isMarked[idx]){
                score+= value;
                 isMarked[idx]=true;
                if((idx-1)>=0){
                    isMarked[idx-1]=true;
                }
                if((idx+1)<nums.size()){
                    isMarked[idx+1]=true;
                }
            }
        }
        return score;
    }
};