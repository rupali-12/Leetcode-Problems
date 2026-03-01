class Solution {
public:
    int minPartitions(string n) {
        int mx=0;
        for(auto ch: n){
            int num = ch-'0';
            mx= max(mx, num);
        }
        return mx;
    }
};