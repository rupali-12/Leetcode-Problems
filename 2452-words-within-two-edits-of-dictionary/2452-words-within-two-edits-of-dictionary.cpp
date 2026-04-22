class Solution {
public:
    bool isPossible(string str, vector<string>& dictionary){
        for(auto s: dictionary){
            int cnt=0;
            for(int i=0;i<str.length(); i++){
                if(str[i]!=s[i]) cnt++;
            }
            if(cnt<=2) return true;
        }
        return false;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        int n=queries.size();

        for(int i=0; i<n; i++){
            if(isPossible(queries[i], dictionary)){
                ans.push_back(queries[i]);
            }
        }
        return ans;
    }
};