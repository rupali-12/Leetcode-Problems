class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n= s.length();
        vector<int>diff(n);
        int mxLength=0, length=0, sum=0, i=0, j=0;
        
        for(int i=0; i<n; i++){
            diff[i] = abs(t[i]-s[i]);
        }
        
        while(j<n){
            sum+= diff[j];
            while(sum>maxCost){
                length--;
                sum-= diff[i];    // diff[i] = t[i]-s[i]
                i++;
            }
            
            length++;
            j++;
            mxLength= max(length, mxLength);
        }
        return mxLength;
    }
};