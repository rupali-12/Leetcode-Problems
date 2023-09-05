class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
               vector<int>ans;
       deque<int>dq;
      
       for(int i=0; i<k; i++){
           while(!dq.empty() && dq.back()<arr[i]){
               dq.pop_back();
           }
           dq.push_back(arr[i]);
       }
       ans.push_back(dq.front());
      for(int i=k; i<arr.size(); i++){
          if(dq.front()==arr[i-k]){    // bcoz if this is true then that element can never be the answer for nxt window 
              dq.pop_front();     
          }
          
        while(!dq.empty() && dq.back()<arr[i]){
               dq.pop_back();
           }
           dq.push_back(arr[i]);
           ans.push_back(dq.front());
      }
        return ans;
    }
};