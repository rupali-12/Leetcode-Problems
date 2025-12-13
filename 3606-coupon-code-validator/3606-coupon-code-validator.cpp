class Solution {
public:
    bool isValid(string code, string bussLine, bool isActive){
        if(!isActive) return false;
        if(bussLine!="electronics" && bussLine!="grocery" && bussLine!="pharmacy" && bussLine!="restaurant") return false;
        if(code=="") return false;
        for(int i=0; i<code.length(); i++){
            if(!isalnum(code[i]) && code[i]!='_') return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n= code.size();

        vector<pair<string, string>>validCoupons;

        // store valid coupons 
        for(int i=0; i<n; i++){
           if(isValid(code[i], businessLine[i], isActive[i])){
               validCoupons.push_back({businessLine[i], code[i]});
            }
        }

        auto lambda = [](pair<string, string>& v1, pair<string, string>&v2){
            if(v1.first == v2.first){
                return v1.second < v2.second;
            }
            return v1.first < v2.first;
        };
        sort(validCoupons.begin(), validCoupons.end(), lambda);
        vector<string>ans;
        for(auto entry: validCoupons){
            ans.push_back(entry.second);
        }
        return ans;
    }
};