class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n= deck.size();
        vector<int>ans(n, 0);
        sort(deck.begin(), deck.end());
        int i=0; // deck index
        
//         // Approach-1: 
//         int j=0;  // ans index
//         bool skip= false;  // initially not skipped
        
//         while(i<n){
//             if(ans[j]==0){
//                 if(skip==false){
//                     ans[j]= deck[i++];
//                 }
//                 skip=!skip;
//             }
            
//             j= (j+1)%n;
//         }
//         return ans;
        
        // Approach-2: Using Queue
        deque<int>dq;
        for(int i=0; i<n; i++){
            dq.push_back(i);
        }
        
        while(i<n){
            int idx= dq.front();
            dq.pop_front();
            ans[idx] = deck[i++];
            
            // insert next element index at back of queue
            int nextidx= dq.front();
            dq.pop_front();
            dq.push_back(nextidx);
        }
        return ans;
    }
};