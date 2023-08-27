struct Pair{
    public:
    char ch;
    int freq;
    
    Pair(char c, int f){
        ch=c;
        freq= f;
    }
};
struct compare{
    public:
    bool operator()(Pair a, Pair b){
        return a.freq < b.freq;
    }
};
class Solution {
public:
    string reorganizeString(string s) {
        map<char, int>mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        
        priority_queue<Pair, vector<Pair>, compare>pq;
        for(auto a: mp){
            pq.push(Pair(a.first, a.second));
        }
        
        // if max count is greater than (n+1)/2 then return ""
        if(pq.top().freq > (s.length()+1)/2){
            return "";
        }
        
        string ans=s;
        int i=0;
        while(!pq.empty()){
            Pair temp = pq.top();
            pq.pop();
           while(temp.freq>0){
               if(i>=ans.length()){
                   i=1;
               }
               
               ans[i]= temp.ch;
               i+=2;
               temp.freq--;
           }
            if(temp.freq>0){
                return "";
            }
        }
        return ans;
    }
};