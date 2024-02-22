class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
       vector<int>In(n+1), Out(n+1);
        for(auto a: trust){
            In[a[1]]++;
            Out[a[0]]++;
        }
        
        for(int i=1; i<=n; i++){
            if(In[i]==n-1 && Out[i]==0){
                return i;
            }
        }
        return -1;
    }
};

