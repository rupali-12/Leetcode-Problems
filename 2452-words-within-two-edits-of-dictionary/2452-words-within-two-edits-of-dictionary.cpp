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
        unordered_set<string>dict;
        for(auto d: dictionary){
            dict.insert(d);
        }

        for(int i=0; i<n; i++){
            if(dict.find(queries[i]) != dict.end() || isPossible(queries[i], dictionary)){
                ans.push_back(queries[i]);
            }
            // else{
            //     if(isPossible(queries[i], dictionary)){
            //         ans.push_back(queries[i]);
            //     }
            // }
        }
        return ans;
    }
};