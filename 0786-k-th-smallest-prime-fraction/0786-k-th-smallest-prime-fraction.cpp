typedef pair<double, pair<int, int>> fii;
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<fii, vector<fii>, greater<fii>>pq;
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                pair<int, int>p= {arr[i], arr[j]};
                double f = static_cast<double>(arr[i])/arr[j];
                pq.push({f, p});
            }
        }
        
        vector<int>ans(2);
        while(k!=1){
            pq.pop();
            k--;
        }
        auto top= pq.top();
        int first = top.second.first;
        int second = top.second.second;
        ans[0] = first;
        ans[1] = second;
        return ans;
    }
};