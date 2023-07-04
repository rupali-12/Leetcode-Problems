class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
       sort(events.begin(), events.end());
        
        priority_queue<int, vector<int>, greater<int>>q;
        int d=0, count=0, i=0, n=events.size();
        
        while(q.size()>0 || i<n){
            if(q.empty()){
                d= events[i][0];
            }
            
            while(i<n && events[i][0]<=d){
                q.push(events[i][1]);
                i++;
            }
            q.pop();
            count++;
            d++;
            
            while(q.size()>0 && q.top()<d){
                q.pop();
            }
        }
        return count;
    }
};