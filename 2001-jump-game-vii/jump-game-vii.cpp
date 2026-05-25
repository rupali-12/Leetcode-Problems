class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();
        vector<bool>vis(n, false);
        queue<int>q;
        q.push(0);
        int farthest = 0;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            if(i==n-1) return true;
        int start = max(farthest, i+minJump);
        int end = min(n-1, i+maxJump);
        for(int j=start; j<=end; j++){
            if(s[j]=='0' && !vis[j]){
                q.push(j);
                vis[j]=true;
            }
        }
        farthest = end+1;
        }
        return false;
    }
};