class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26, 0);
        int ans=0;
        for(char ch: word){
            freq[ch-'a']++;
        }

        sort(freq.begin(), freq.end(), greater<int>());

        for(int i=0; i<26; i++){
            if(freq[i]==0) break;  // 4 3 2 1 0 0 0  for optimization
            ans+= freq[i]*(i/8 + 1);
        }
        return ans;
    }
};