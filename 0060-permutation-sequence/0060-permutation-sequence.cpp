class Solution {
public:
    // Approach-1: TLE for large Test cases
    // void solve(string &ch, int index, vector<string>&ans){
    //     if(index==ch.size()){
    //         ans.push_back(ch);
    //         return;
    //     }
    //     for(int i= index; i<ch.length(); i++){
    //         swap(ch[i], ch[index]);
    //         solve(ch, index+1, ans);
    //         swap(ch[i], ch[index]);
    //     }
    // }
    // string getPermutation(int n, int k) {
    //    vector<string>ans;
    //     string ch="";
    //     for(int i=1; i<=n;i++){
    //         ch+= char(i+'0');
    //     }
    //     int index=0;
    //     solve(ch, index, ans);
    //     sort(ans.begin(), ans.end());
    //     return ans[k-1];
    // }
    
    // Approach-2: Optimized 
    string getPermutation(int n, int k) {
       int fact=1;
        vector<int>nums;
        for(int i=1; i<n; i++){
            fact = fact*i;
            nums.push_back(i);
        }
        // insert last element
        nums.push_back(n);
        
        string ans="";
        k= k-1;   // As 0-based indexing
        while(true){
            ans= ans+ to_string(nums[k/fact]);
            nums.erase(nums.begin() + k/fact);
            if(nums.size()==0) break;
            k= k%fact;
            fact= fact/nums.size();
        }
        return ans;
    }
};