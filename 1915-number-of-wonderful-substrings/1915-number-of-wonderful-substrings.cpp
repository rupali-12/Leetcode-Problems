class Solution {
public:
    int n;
    bool isWonderful(string &temp){
        unordered_map<char, int>mp;
        for(auto w: temp){
            mp[w]++;
        }
        int count=0;
        for(auto m: mp){
            if(m.second%2 !=0){
                count++;
            }
        }
        return count<=1 ? true: false; 
    }
    
    long long wonderfulSubstrings(string word) {
        n= word.length();
        
        // // Approach-1: Brute force TLE 
         // long long ans=0;
        // for(int i=0; i<n; i++){
        //     string temp="";
        //     for(int j=i; j<n; j++){
        //         temp+= word[j];
        //         if(isWonderful(temp)){
        //             ans++;
        //         }
        //     }
        // }
        
        // Approach-2: Optimize using xor
        unordered_map<long long, long long>mp;
         long long ans=0;
        long long cum_xor=0;
        mp[0]= 1;   // 0 is already seen in past
        
        for(auto ch: word){
            int shift= ch-'a';
            
            cum_xor^= (1<<shift);
            ans+= mp[cum_xor];   // case when all char count is even in count
            
            // case if char count is 1 
            for(char ch1='a'; ch1<='j'; ch1++){
                shift= ch1-'a';
                long long chk_xor = cum_xor^(1<<shift);
                ans+= mp[chk_xor];
            }
            
            mp[cum_xor]++;
        }
        
        return ans;
        
    }
};