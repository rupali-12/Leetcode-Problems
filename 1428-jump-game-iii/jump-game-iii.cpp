class Solution {
public:
    int n;
    bool isPossible(int i, vector<int>&arr, vector<bool>&visited){
        if(i<0 || i>=n) return false;
        if(visited[i]) return false;
        if(arr[i]==0) return true;

        visited[i]=true;
        bool front=isPossible(i+arr[i], arr, visited);
        bool back=isPossible(i-arr[i], arr, visited);
        
        return front || back;
    }
    bool canReach(vector<int>& arr, int start) {
        n= arr.size();
        vector<bool>visited(n, false);
        return isPossible(start, arr, visited);
    }
};