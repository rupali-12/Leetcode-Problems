class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n= nums.size();
        vector<pair<int, int>>vec(n);
        
        for(int i=0; i<n; i++){
            vec[i]= make_pair(nums[i], i);
        }
        
        make_heap(begin(vec), end(vec), greater<>());
        
        while(k--){
            pop_heap(begin(vec), end(vec), greater<>());  // this will resize heap and place smallest at back
            pair<int, int>temp= vec.back();
            vec.pop_back();
            int x= temp.first;
            int idx= temp.second;
            
            nums[idx]= x*multiplier;
            vec.push_back({nums[idx], idx});
            push_heap(begin(vec), end(vec), greater<>());
        }
        return nums;
    }
};