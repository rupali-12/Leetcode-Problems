class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<string>st;
        for(int i=0; i<arr1.size(); i++){
            string temp=to_string(arr1[i]);
            string s;
            for(int j=0; j<temp.length(); j++){
                s.push_back(temp[j]);
                st.insert(s);
            }
        }

        int mxLength=0;
        for(int i=0; i<arr2.size(); i++){
            string temp=to_string(arr2[i]);
            string s;
            for(int j=0; j<temp.length(); j++){
                s.push_back(temp[j]);
                if(st.find(s)!=st.end()){
                    mxLength = max(mxLength, (int)s.length());
                }
            }
        }
        return mxLength;
    }
};