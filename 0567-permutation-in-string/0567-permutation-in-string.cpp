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
        int temp1[26]={0};
        
        // Store count of every characters in s1
        for(int i=0; i<s1.length(); i++){
            int ind = s1[i]-'a';
            temp1[ind]++;
        }
        int i=0, winSize=s1.length();
        int temp2[26]={0};
      while(i<winSize && i<s2.length()){
          int ind= s2[i]-'a';
          temp2[ind]++;
          i++;
      }
         if(comp(temp1, temp2)){
           return true;   
          }
        
        while(i<s2.length()){
            int n= s2[i]-'a';
            temp2[n]++;
            n= s2[i-winSize]-'a';
            temp2[n]--;
            i++;
            if(comp(temp1, temp2)){
                return true;
            }
        }
        return false;
    }
};