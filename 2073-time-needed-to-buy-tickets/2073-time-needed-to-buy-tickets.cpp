class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time=0;
        int n = tickets.size();
        deque<pair<int, int>>dq;
        for(int i=0; i<n; i++){
            pair<int, int>p = make_pair(tickets[i], i);
            dq.push_back(p);
        }
        
        while(true){
            int size=dq.size();
            while(size--){
                pair<int, int>front =dq.front();
                front.first--;
                time++;
                if(front.first==0){
                    if(front.second ==k){
                        return time;
                    }
                    else{
                        dq.pop_front();
                    }
                }
                else{
                    dq.pop_front();
                    dq.push_back(front);
                }
            }
        }
        return time;
    }
};