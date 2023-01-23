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
    bool checkInclusion(string s1, string s2) {
        int temp[26]={0};
        for(int i=0; i<s1.length(); i++){
            int ind = s1[i]-'a';
            temp[ind]++;
        }
        
       int i=0;
        int count2[26]={0};
        int winSize = s1.length();
        while(i<winSize && i<s2.length()){
            char ch = s2[i];
            int ind = ch-'a';
            count2[ind]++;
            i++;
        }
        if(comp(count2, temp)){
            return true;
        }
        
        while(i<s2.length()){
            char newChar = s2[i];
            int ind = newChar -'a';
            count2[ind]++;
            
            char oldChar = s2[i-winSize];
            int ind1 = oldChar-'a';
            count2[ind1]--;
            i++;
            
            if(comp(count2, temp)){
                return true;
            }            
        }
        return false;
    }
};