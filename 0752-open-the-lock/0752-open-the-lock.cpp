class Solution {
public:
    void fillNeighbour(queue<string>&que, string curr, unordered_set<string>&st){
        for(int i=0; i<4; i++){
            char ch= curr[i];
            char dec = ch=='0' ? '9': ch-1;
            char inc = ch=='9' ? '0': ch+1;

            curr[i]=dec;
            if(st.find(curr) == st.end()){
               que.push(curr);
               st.insert(curr);
            }

            curr[i]=inc;
            if(st.find(curr) == st.end()){
               que.push(curr);
               st.insert(curr);
            }
            curr[i]=ch;
        }
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>st(deadends.begin(), deadends.end());

        queue<string>que;
        string start= "0000";
          if(st.find(start)!=st.end()){  //  is invalid case 
            return -1;
        }
        
        que.push(start);
        int level=0;
        while(!que.empty()){
            int size= que.size();
            while(size--){
                string curr = que.front();
                que.pop();

                if(curr==target){
                    return level;
                }

                fillNeighbour(que, curr, st);
            }
            level++;
        }
        return -1;
    }
};