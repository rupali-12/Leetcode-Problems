class Solution {
public:
    bool isPossible(vector<vector<int>>&tasks, int mid){
        for(auto task: tasks){
            int actual = task[0];
            int minimum = task[1];
            if(minimum>mid) return false;
            else{
                mid-=actual;
            }
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int n=tasks.size();
        int left =0, right =1e9+7;
        int result=INT_MAX;

        auto lambda = [](auto &tasks1, auto &tasks2){
            int diff1 = tasks1[1]-tasks1[0];
            int diff2 = tasks2[1]-tasks2[0];
            return diff1 > diff2;
        };

        sort(begin(tasks), end(tasks), lambda);

        while(left<=right){
            int mid = left + (right-left)/2;
            if(isPossible(tasks, mid)){
                result=mid;
                right= mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return result;
    }
};