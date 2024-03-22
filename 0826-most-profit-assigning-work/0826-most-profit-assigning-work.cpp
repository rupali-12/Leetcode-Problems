class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n= worker.size();
        sort(worker.begin(), worker.end());
        vector<pair<int, int>>nums(profit.size());
        for(int i=0; i<profit.size(); i++){
            pair<int, int>p= make_pair(difficulty[i], profit[i]);
            nums[i]= p;
        }
        sort(nums.begin(), nums.end());
        
        int maxProfit=0, tempProfit=0;
        
        for(int i=0, j=0; i<n; i++){
            while(j<n && nums[j].first<= worker[i]){    
                tempProfit =max(tempProfit, nums[j].second);   // store max profit for all worker whose difficulty <= worker[i]
                j++;
            }
            
            if(j>0){
                maxProfit+= tempProfit;
            }
        }
        return maxProfit;
    }
};

