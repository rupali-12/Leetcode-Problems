class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        
        for(auto &a: asteroids){
            while(!s.empty() && s.top()>0 && a<0){
                int sum= s.top() + a;
                if(sum>0){    // right
                    a=0;
                // break;
                }
                else if(sum<0){    // left
                    s.pop();
                }
                else{
                    a=0;
                    s.pop();
                }
            }
            
            if(a!=0){
                s.push(a);
            }
        }
        
        int size= s.size();
        vector<int>ans(size);
        int i= size-1;
        while(!s.empty()){
            ans[i]= s.top();
            s.pop();
            i--;
        }
        return ans;
    }
};