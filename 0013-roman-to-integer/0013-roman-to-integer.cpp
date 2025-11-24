class Solution {
public:
    int romanToInt(string s) {
        int sum=0, i=0;
        unordered_map<char, int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;

        while(i<s.length()){
            if((i<s.length()-1) && (mp[s[i]]<mp[s[i+1]])){
                sum+= mp[s[i+1]]- mp[s[i]];
                i+=2;
            }
            else{
                sum+= mp[s[i]];
                i+=1;
            }
        }
        return sum;
    }
};