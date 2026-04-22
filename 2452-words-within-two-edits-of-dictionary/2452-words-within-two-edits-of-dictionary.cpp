class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        int n=queries.size();

        for (auto &q : queries) {
            for(auto s: dictionary){
            int cnt=0;
            for(int i=0;i<q.length(); i++){
                if(q[i]!=s[i]) {
                    cnt++;
                    if(cnt>2) break;
                }
            }
            if(cnt<=2){
                ans.push_back(q);
                break;
            }
            }
        }
        return ans;
    }
};