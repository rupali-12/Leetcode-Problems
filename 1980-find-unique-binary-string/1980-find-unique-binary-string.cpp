class Solution {
public:
    string decToBin(int num, int count){
        string ans="";
        while(num>0 || count>0){
            int rem= num%2;
            num/=2;
            ans = char('0'+rem) + ans;
            count--;
        }
        return ans;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>st;
        int n= nums.size();
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }
        string ans;
 for (int i = 0; i < (1 << n); i++) {
        string temp = decToBin(i, n);
        if (st.find(temp) == st.end()) {
            ans= temp;
            return temp;
        }
    }
        return ans;
    }
};