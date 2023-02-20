class Solution {
public:
     // int largestRectangleArea(vector<int>& heights) {
    // // Approach-1>> Brute Force>>>>O(n^2)-->TLE
    //     int n=heights.size();
    //     int area=0;
    //     for(int i=0;i <n; i++){
    //         int currArea=0;
    //         int minHeight=INT_MAX;
    //         for(int j=i; j<n; j++){
    //             minHeight =min(minHeight, heights[j]);
    //             currArea = max(currArea, minHeight*(j-i+1));
    //         }
    //         area =max(area, currArea);
    //     }
    //    return area;
     // }
         
         
         // Approach-2>> Using Stack>>>>>
    // here we have to push indexes not values 
    // and compare it with value at that index which is stored at top of stack
    vector<int>nextSmallerElements(vector<int>& heights, int n){
        vector<int>ans(n);
        stack<int>s;
        s.push(-1);
        for(int i=n-1; i>=0; i--){
                while(s.top()!=-1 && heights[s.top()]>=heights[i]){
                    s.pop();
                }
                // ans.push_back(s.top());
            ans[i]=s.top();
                 s.push(i);
        }
        return ans;
    }
     vector<int>prevSmallerElements(vector<int>& heights, int n){
        vector<int>ans(n);
        stack<int>s;
        s.push(-1);
        for(int i=0; i<n; i++){
                while(s.top()!=-1 &&  heights[s.top()]>=heights[i]){
                    s.pop();
                }
                // ans.push_back(s.top());
             ans[i]=s.top();
                s.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
         int n=heights.size();
         vector<int>next(n);
         next = nextSmallerElements(heights, n);
         
          vector<int>prev(n);
         prev = prevSmallerElements(heights, n);
         int maxArea=INT_MIN;
         for(int i=0; i<n; i++){
             int length =heights[i];
             if(next[i]==-1){
                 next[i]=n;
           }
             int width = next[i]-prev[i]-1;
            int newArea= length *width;
             maxArea =max(maxArea, newArea);
         }
        return maxArea;
    }
};