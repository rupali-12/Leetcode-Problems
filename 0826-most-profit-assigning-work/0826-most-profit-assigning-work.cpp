class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n= profit.size(), m= worker.size();
        
//         // Approach-1: Using Heap sort 
//         priority_queue<pair<int, int>>pq;
//         for(int i=0; i<n; i++){
//             int prof = profit[i];
//             int diff = difficulty[i];
            
//             pq.push({prof, diff});
//         }
        
//         int i=0, totalProfit=0;
//         // sort workers in desc 
//         sort(worker.begin(), worker.end(), greater<int>());
        
//         while(i<m && !pq.empty()){
//             if(pq.top().second > worker[i]){   // worker is incapable
//                 pq.pop();
//             }
//             else{
//                 totalProfit+= pq.top().first;
//                 i++;
//             }
//         }
//         return totalProfit;
        
        // Approach-2: Using Preprocessing
        vector<pair<int, int>>vec;
        for(int i=0; i<n; i++){
            vec.push_back({difficulty[i], profit[i]});
        }
        
        sort(vec.begin(), vec.end());
        
        // pre processing to find the maximum profit of worker till index i at constant time 
        for(int i=1; i<n; i++){
            vec[i].second= max(vec[i].second, vec[i-1].second);
        }
        
        int totalProfit=0;
        for(int i=0; i<m; i++){
            int workerLevel = worker[i];
            
            int l=0, r= vec.size()-1;
            int maxProfit=0;
            while(l<=r){
                int mid= l+(r-l)/2;
                if(worker[i]>=vec[mid].first){
                    maxProfit= max(maxProfit, vec[mid].second);
                    l= mid+1;
                }
                else{
                    r= mid-1;
                }
            }
            totalProfit+= maxProfit;
        }
        return totalProfit;
    }
};