class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n= profit.size(), m= worker.size();
        
        // Approach-1: Using Heap sort 
        priority_queue<pair<int, int>>pq;
        for(int i=0; i<n; i++){
            int prof = profit[i];
            int diff = difficulty[i];
            
            pq.push({prof, diff});
        }
        
        int i=0, totalProfit=0;
        // sort workers in desc 
        sort(worker.begin(), worker.end(), greater<int>());
        
        while(i<m && !pq.empty()){
            if(pq.top().second > worker[i]){   // worker is incapable
                pq.pop();
            }
            else{
                totalProfit+= pq.top().first;
                i++;
            }
        }
        return totalProfit;
    }
};