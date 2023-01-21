class Solution {
public:
    void reverseString(vector<char>& s) {
        int n =s.size()-1;
        int start=0;
        while(start<n){
            swap(s[start], s[n]);
            start++; n--;
        }
    }
};