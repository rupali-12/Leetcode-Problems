class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m= rolls.size();
        int observed_sum=0;
        for(auto a: rolls){
            observed_sum+= a;
        }
        
        int req_sum= mean*(n+m);
        
        int missing_sum = req_sum - observed_sum;
        
        // check if it is possible or not 
        if(missing_sum<n || missing_sum > n*6) return {};
        
        
        vector<int>ans(n, 1);   // Initialize by giving minimum roll value
        
        // substract n from missing_sum as n sum already distributed 
        missing_sum-= n;
        
        // Distribute rem across each roll 
        for(int i=0; i<n; i++){
            // give max as possible , although max value you can give is 5  so choose min(5, missing_sum)
            ans[i]+= min(5, missing_sum);
            
            // reduce from missing_sum whatever you assigned 
            missing_sum-= min(5, missing_sum);
            
            // check is missing sum =0 if it is then break 
            if(missing_sum==0) break;
        }
        return ans;
    }
};




