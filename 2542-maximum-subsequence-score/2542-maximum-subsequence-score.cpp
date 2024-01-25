class Solution {
public:
    priority_queue<long long, vector<long long>, greater<long long>>pq;
    
     void removeFromQueue(int num){
        vector<int>temp;
        while(!pq.empty()){
            int x= pq.top();
            pq.pop();
            if(x==num) break;
            temp.push_back(x);
        }
        for(auto &a: temp){
            pq.push(a);
        }
        return;
    }
    long long solveRec(vector<int>& nums1, vector<int>& nums2, long long sum, long long mini, int i, int count, int k){
        if(count==k) return sum*mini;
        if(i>=nums1.size()) return 0;
        
        pq.push(nums2[i]);
        long long take = solveRec(nums1, nums2, sum+nums1[i], pq.top(), i+1, count+1, k);
        
        // if not taken then we have to remve nums2[i] rom priority queue
        removeFromQueue(nums2[i]);
        long long notTake = solveRec(nums1, nums2, sum, mini, i+1, count, k);
        
        return max(take, notTake);
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        // // Approach-1: Recursion
        // // (sum, mini, index, count)
        // return solveRec(nums1, nums2, 0, INT_MAX, 0, 0, k);
        
        // Approach 2: Optimized way (priority Queue)
        vector<pair<int, int>>vec(nums1.size());
        for(int i=0; i<nums1.size(); i++){
            vec[i] ={nums1[i], nums2[i]};
        }
        
        auto lambda = [&](auto &p1, auto &p2){
          return p1.second > p2.second;  
        };
        
        sort(begin(vec), end(vec), lambda);
        
        // store k element sum 
        long long kSum =0;
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0; i<k; i++){
            kSum+= vec[i].first;
            pq.push(vec[i].first);
        }
        
        long long ans = kSum* vec[k-1].second;
        for(int i=k; i<nums1.size(); i++){
            kSum+= vec[i].first - pq.top();
            pq.pop();
            pq.push(vec[i].first);
            ans = max(ans, kSum*vec[i].second);
        }
        return ans;
    }
};