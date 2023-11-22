class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans(k);
        priority_queue<pair<int, int>>pq;
        for(int i=0; i<arr.size(); i++){
            pq.push({abs(arr[i]-x), arr[i]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        int n= pq.size();
        int i=0;
        while(n--){
            ans[i++] = pq.top().second;
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};