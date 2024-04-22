class Solution {
public:
    void fillNeighbours(queue<string>&q, unordered_set<string>&st, string curr){
       for(int i=0; i<4; i++){
           char ch = curr[i];
           char inc= ch=='9'?'0': ch+1;
           char dec= ch=='0'?'9': ch-1;
           
           // increment 
           curr[i]= inc;
           if(st.find(curr)==st.end()){
               st.insert(curr);
               q.push(curr);
           }
           
           // decrement 
           curr[i]= dec;
           if(st.find(curr)==st.end()){
               st.insert(curr);
               q.push(curr);
           }
           
           // make curr as previous 
           curr[i]=ch;
       }    
        return;
    }
    
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>st(begin(deadends), end(deadends));
        
        string start="0000";
        if(st.find(start)!=st.end()){  //  is invalid case 
            return -1;
        }
        
        int level=0;
        queue<string>q;
        q.push(start);
        
        while(!q.empty()){
           int size= q.size();
            
            while(size--){
                string curr= q.front();
                q.pop();
                
                if(curr==target){
                    return level;
                }
                
                fillNeighbours(q, st, curr);
            }
            level++;
        }
        return -1;
    }
};