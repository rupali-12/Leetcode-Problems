class Solution {
public:
    int minSteps(string s, string t) {
        map<char, int>mp;
        for(auto a: s){
            mp[a]++;
        }
        for(auto a: t){
            mp[a]--;
        }
        int sum=0;
        for(auto a: mp){
            sum+= abs(a.second);
        }
        
        sum/=2; // as a repace by b 1 time or b replace by a 1 time is same so we have to divide the sum by 2
        return sum;
    }
};