class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
//         // Approach-1: TLE for large Inputs 
//         unordered_map<int, int>mp;
//         deque<int>q;
//         int winner=-1;
//         int winCount=0;
        
//          for(auto a: arr){
//              q.push_back(a);
//          }
        
//         while(winCount!=k){
//             int top1= q.front();
//             q.pop_front();
//             int top2= q.front();
//             q.pop_front();
//             int loser;
            
//             if(top1 > top2){
//                 q.push_front(top1);
//                 q.push_back(top2);
//                 winner= top1;
//                 loser=top2;
//             }
//             else{
//                 q.push_front(top2);
//                 q.push_back(top1);
//                 winner= top2;
//                 loser=top1;
//             }
//             mp[winner]++;
//             mp[loser]--;
//             if(mp[winner]==k){
//                 return winner;
//             }
//         }
//         return winner;
        
        // Approach-2: Optimized 
        int element =arr[0];
        int win=0;
        for(int i=1; i<arr.size(); i++){
            if(arr[i]>element){
                element= arr[i];
                win=0;
            }
            if(++win==k){
                // break;
                return element;
            }
        }
        return element;
    }
};