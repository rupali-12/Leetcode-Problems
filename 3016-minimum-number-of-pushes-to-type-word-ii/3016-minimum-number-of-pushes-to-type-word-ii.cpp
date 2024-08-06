class Solution {
public:
    int minimumPushes(string word) {
//         // Approach-1: Brute force  // Better work for distinct characters in word only.
//         unordered_map<int, int>mp;
//         int assigned =2, ans=0;
//         for(auto &ch: word){
//             if(assigned>9){
//                 assigned = 2;
//             }
            
//             mp[assigned]++;
//             ans+= mp[assigned];
//             assigned++;
//         }
        
//         return ans;
        
        // Approach-2: For duplicate characters as well 
        vector<int>freq(26, 0);
        for(auto ch: word){
            freq[ch-'a']++;
        }
        
        // sort in descending order 
        sort(freq.begin(), freq.end(), greater<int>());
        
        int ans=0;
        
        for(int i=0; i<26; i++){
            int frequency = freq[i];
            int pressCount = (i/8) + 1;
            ans += frequency*pressCount;
        }
        return ans;
    }
};