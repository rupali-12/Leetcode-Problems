class Solution {
public:
    int solve(string s, string temp, int index, unordered_set<string>&st){
        if(index==s.size()){
            return 0;
        }
        else{
             temp+=s[index];
            // case of taken bar 
             // int taken=INT_MIN/2, notTaken=INT_MIN/2;
              int taken=0, notTaken=0;
            if(st.find(temp)==st.end()){
               st.insert(temp);
                taken = 1+ solve(s, "",index+1,st);
                st.erase(temp);
            }
            // case of not Taken bar
             notTaken = solve(s, temp,index+1, st);
           return max(taken, notTaken);
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        // temp, ans, temp;
        return solve(s, "",  0, st);

    }
};