class Solution {
public:
    vector<string>getTokens(string str){
        vector<string>ans;
         stringstream ss(str);
        string token;
        while(getline(ss, token, '.')){
            ans.push_back(token);
        }
        return ans;
    }
    int compareVersion(string version1, string version2) {
        vector<string>v1 = getTokens(version1);
        vector<string>v2 = getTokens(version2);
        
        int i=0, m=v1.size(), n= v2.size();
        while(i<m || i<n){
            int a = i<m ? stoi(v1[i]):0;
            int b= i<n ? stoi(v2[i]): 0;
            
            if(a<b) return -1;
            else if(a>b) return 1;
            i++;
        }
        return 0;
    }
};