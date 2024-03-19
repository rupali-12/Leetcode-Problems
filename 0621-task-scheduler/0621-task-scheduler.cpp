class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>mp(26, 0);
        for(auto ch: tasks){
            mp[ch-'A']++;
        }
        
        int time=0;
        priority_queue<int>pq;
        
        // push all char with freq>0
        for(int i=0; i<26; i++){
            if(mp[i]>0){
                pq.push(mp[i]);
            }
        }
        
        // process queue
        while(!pq.empty()){
            vector<int>temp;
            for(int i=1; i<=n+1; i++){
                if(!pq.empty()){
                    int freq = pq.top();
                pq.pop();
                freq--;
                temp.push_back(freq);
                }
            }
            
            // push temp values in pq again
            for(auto &f: temp){
               if(f>0){
                    pq.push(f);
               }
            }
            
            if(pq.empty()){
               time+= temp.size(); 
            }
            else{
                time+= n+1;
            }   
        }
        return time;
    }
};