class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n= tickets.size();
        deque<pair<int, int>>dq;
        for(int i=0; i<n; i++){
            pair<int, int>p= make_pair(tickets[i], i);
            dq.push_back(p);
        }
        int time=0;
        while(true){
            int size= dq.size();
            while(size--){
                auto front= dq.front();
                int val= front.first;
                int idx= front.second;
                val--;
                time++;
                if(val==0){
                    if(idx==k){
                        return time;
                    }
                    else{
                        dq.pop_front();
                    }
                }
                else{
                    dq.pop_front();
                    dq.push_back({val, idx});
                }
            }
        }
        return time;
    }
};

