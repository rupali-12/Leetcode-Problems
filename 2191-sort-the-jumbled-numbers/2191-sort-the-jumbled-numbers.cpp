class Solution {
public:
    string mappedNum(string str, vector<int>& mapping){
        for(int i=0; i<str.length(); i++){
            int digit = str[i]-'0';
            digit= mapping[digit];
            
            str[i] =digit + '0';
        }
        return str;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n= nums.size();
        
        vector<pair<int, int>>v;
        
        for(int i=0; i<n; i++){
            string strNum = to_string(nums[i]);
            
            string NewNumStr= mappedNum(strNum, mapping);
            int mappedNum= stoi(NewNumStr);
            v.push_back({mappedNum, i});
        }
        
        sort(v.begin(), v.end());
        
        vector<int>ans;
        for(auto &a: v){
            int originalIndex = a.second;
            
            ans.push_back(nums[originalIndex]);
        }
        return ans;
    }
};