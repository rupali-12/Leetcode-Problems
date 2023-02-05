class Solution {
public:
    bool comp(int a[], int b[]){
        for(int i=0; i<26; i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
   vector<int> findAnagrams(string s, string p) {
        int temp[26]={0};
        
        // Store count of every characters in s1
        for(int i=0; i<p.length(); i++){
            int ind = p[i]-'a';
            temp[ind]++;
        }
        
       int i=0;
        int count2[26]={0};
        int winSize = p.length();
       vector<int>ans;
        while(i<winSize && i<s.length()){
            char ch = s[i];
            int ind = ch-'a';
            count2[ind]++;
            i++;
        }
        if(comp(count2, temp)){
           ans.push_back(i-p.length());
        }
        
        while(i<s.length()){
            char newChar = s[i];
            int ind = newChar -'a';
            count2[ind]++;
            
            char oldChar = s[i-winSize];
            int ind1 = oldChar-'a';
            count2[ind1]--;
            i++;
            
            if(comp(count2, temp)){
               ans.push_back(i-p.length());
            }            
        }
        return ans;
    }
}; 