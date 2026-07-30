class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<int, int>mp;
        int assigned=2, ans=0;
        for(char ch: word){
           if(assigned > 9){
              assigned =2;
           }

           mp[assigned]++;
           ans+= mp[assigned];
           assigned++;
        }
        return ans;
    }
};