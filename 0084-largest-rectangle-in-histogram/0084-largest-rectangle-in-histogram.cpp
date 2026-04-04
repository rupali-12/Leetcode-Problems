class Solution {
public:
    // int largestRectangleArea(vector<int>& heights) {
        // // Approach-1: Brute Force: T(O^2)
        // int n=heights.size();
        // int area=0;
        // for(int i=0; i<n; i++){
        //     int currArea = 0;
        //     int minHeight = INT_MAX;
        //     for(int j=i; j<n; j++){
        //         minHeight = min(minHeight, heights[j]);
        //         currArea = max(currArea, minHeight*(j-i+1));
        //     }
        //     area = max(area, currArea);
        // }
        // return area;
    // }

    vector<int>prevSmaller(vector<int>arr, int n){
        stack<int>st;
        vector<int>ans(n);
        st.push(-1);
        for(int i=0; i<n; i++){
            while(st.top()!=-1 && arr[st.top()] >= arr[i]){
                st.pop();
            }

            ans[i] =st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int>nextSmaller(vector<int>arr, int n){
        stack<int>st;
        vector<int>ans(n);
        st.push(-1);
        for(int i=n-1; i>=0; i--){
            while(st.top()!=-1 && arr[st.top()] >= arr[i]){
                st.pop();
            }

            ans[i] =st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        // Approach: 2 Optimize using stack and storing nextSmaller and prev smaller 
        int n= heights.size();
        vector<int>prev(n);
        prev = prevSmaller(heights, n);

        vector<int>next(n);
        next = nextSmaller(heights, n);
       
        int ans= INT_MIN;
        for(int i=0; i<n; i++){
            int height = heights[i];
            if(next[i]==-1){
                next[i]= n;
            }
            int breadth = next[i] - prev[i] -1;
            ans=max(ans, height*breadth);
        }
        return ans;
    }
};