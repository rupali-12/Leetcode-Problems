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
    //  }
         
         
         // Approach-2>> Using Stack>>>>>
    // here we have to push indexes not values 
    // and compare it with value at that index which is stored at top of stack

    vector<int>prevSmaller(vector<int> arr, int n){
         stack<int>s;
   vector<int>ans(n);
   s.push(-1);
   for(int i=0; i<n; i++){
     while (s.top()!=-1 && arr[s.top()] >= arr[i]) {
       s.pop();
     }
         ans[i]= s.top();
         s.push(i);
   }
   return ans;
    }
     vector<int>nextSmaller(vector<int> arr, int n){
         stack<int>s;
   vector<int>ans(n);
   s.push(-1);
   for(int i=n-1; i>=0; i--){
     while (s.top()!=-1 && arr[s.top()] >= arr[i]) {
       s.pop();
     }
         ans[i]= s.top();
         s.push(i);
   }
   return ans;
    }
      int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>prev(n);
          prev= prevSmaller(heights, n);
          
        vector<int>next(n);
          next = nextSmaller(heights, n);
          int ans= INT_MIN;
        for(int i=0; i<n; i++){
            int len = heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int breadth = next[i]-prev[i]-1;
            ans= max(ans, len*breadth);
        }
          return ans;
    }
};