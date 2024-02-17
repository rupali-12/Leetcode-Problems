class Solution {
public:
    
	// // Approach -1 DP 
	// int len = -1;
	// int solve(int idx, int n, vector<int> &heights, int bricks, int ladders, vector<vector<int>>&dp) {
	// 	if(idx == n - 1) 
	// 		return 0;
	// 	if(bricks == 0 && ladders == 0 && heights[idx+1] > heights[idx]) 
	// 		return 0;
	// 	if(dp[bricks][ladders] != -1)
	// 		return dp[bricks][ladders];
	// 	if(heights[idx] >= heights[idx + 1])
	// 		dp[bricks][ladders] = 1 + solve(idx+1, n, heights, bricks, ladders, dp);
	// 	else {
	// 		int a = 0, b = 0;
	// 		if(bricks >= heights[idx + 1] - heights[idx])
	// 		a = 1 + solve(idx+1, n, heights, bricks - (heights[idx+1] - heights[idx]), ladders, dp);
	// 		if(ladders > 0)
	// 		b = 1 + solve(idx+1, n, heights, bricks, ladders - 1, dp);
	// 		dp[bricks][ladders] = max(a, b);
	// 	}
	// 	return dp[bricks][ladders];
	// }
	// int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
	// 	int n = heights.size(); 
	// 	vector<vector<int>>dp(bricks + 1, vector<int>(ladders + 1, -1));
	// 	return solve(0, n, heights, bricks, ladders, dp);
	// }
     
    // Approach -2 : Priority queue 
    	int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
		int n = heights.size(); 
            priority_queue<int>pq;
		for(int i=1; i<n; i++){
            int diff = heights[i]-heights[i-1];
            if(diff>0){
                pq.push(diff);
                bricks-= diff;
                if(bricks<0){
                    bricks += pq.top();
                    pq.pop();
                    ladders--;
                    if(ladders<0){
                        return i-1;
                    }
                }
            }
        }
            return n-1;
	}
    
};

