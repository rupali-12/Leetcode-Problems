class Solution {
public:
    // Approach-
    // 1. find wage/quality and store in vector {ratio, quality}
    // 2. sort ratio vector
    // 3. do first k processing and do after left out processing 
    
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n= wage.size();
        vector<pair<double, int>>ratio;
        for(int i=0; i<n; i++){
            double r = static_cast<double>(wage[i])/quality[i];
            ratio.push_back({r, quality[i]});
        }
        
        int qualitySum=0;
        double maxRate = 0.0;
        priority_queue<int>mxheap;
        
        // ************ sort ratio vector *************************
        sort(ratio.begin(), ratio.end());
        
        for(int i=0; i<k; i++){
            qualitySum+= ratio[i].second;
            maxRate = max(maxRate, ratio[i].first);
            mxheap.push(ratio[i].second);
        }
        
        double ans = maxRate*qualitySum;
        for(int i=k; i<n; i++){
            qualitySum-= mxheap.top();
            maxRate= max(maxRate, ratio[i].first);
            mxheap.pop();
            
            // store 
            qualitySum+= ratio[i].second;
            mxheap.push(ratio[i].second);
            ans = min(ans, (maxRate*qualitySum));
        }
        return ans;
    }
};