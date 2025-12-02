class Solution {
public:
    bool comp(vector<int>count1, vector<int>count2){
         for(int i=0; i<26; i++){
            if(count2[i]!=count1[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
    vector<int>count1(26, 0);
    vector<int>count2(26, 0);

    //    store count character of s1
        for(int i=0; i<s1.length(); i++){
            count1[s1[i]-'a']++;
        }

    //    process first window 
    int winSize=s1.length();
    int i=0;
    while(i<winSize && i<s2.length()){
       int idx = s2[i]-'a';
       count2[idx]++;
       i++;
    }

    if(comp(count1, count2)){
        return true;
    }

    // process remaining window 
    while(i<s2.length()){
       int indNew = s2[i]-'a';
       count2[indNew]++;

       int indOld = s2[i-winSize]-'a';
       count2[indOld]--;
       i++;
       if(comp(count1, count2)) return true;
    }

    return false;

    }
};