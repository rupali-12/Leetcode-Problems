class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n= positions.size();
        vector<int>actualIndex(n);
        iota(begin(actualIndex), end(actualIndex), 0);   // 0, 1, 2, 3,......n-1

        auto lambda = [&](int i, int j){
            return positions[i]<positions[j];
        };

        sort(actualIndex.begin(), actualIndex.end(), lambda);

        stack<int>st;
        vector<int>ans;
       for(int currIndex: actualIndex){
        if(directions[currIndex]=='R'){
            st.push(currIndex);
        }
        else{
           while(!st.empty() && healths[currIndex]>0){
             int topIndex =st.top();
            st.pop();
            if(healths[topIndex]>healths[currIndex]){
                healths[currIndex]=0;
                healths[topIndex]--;
                st.push(topIndex);
            }
            else if(healths[topIndex]<healths[currIndex]){
                healths[topIndex]=0;
                healths[currIndex]--;
            }
            else{
                healths[topIndex]=0;
                healths[currIndex]=0;
            }
        }
           }
       }
        for(int i=0; i<n; i++){
           if(healths[i]>0){
            ans.push_back(healths[i]);
           }
        }
        return ans;
    }
};