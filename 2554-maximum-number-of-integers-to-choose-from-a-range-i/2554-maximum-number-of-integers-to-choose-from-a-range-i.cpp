class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>st;
        for(auto num: banned){
            st.insert(num);
        }
        int currSum=0, count=0;
        for(int i=1;i<=n; i++){
            if(st.find(i)==st.end()){
                if(currSum+i <=maxSum){
                    currSum+= i;
                    count++;
                }
            }
        }
        return count;
    }
};
