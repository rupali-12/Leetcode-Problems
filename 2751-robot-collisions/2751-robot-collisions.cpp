class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n= positions.size();
        vector<int>actualIndex(n);   //0, 1,2,3,4,5........n-1  
    iota(begin(actualIndex), end(actualIndex), 0);   //  0, 1, 2, 3......n-1
    
    auto lambda= [&](int &i, int &j){
        return positions[i]<positions[j];
    };
    sort(actualIndex.begin(), actualIndex.end(), lambda);
        vector<int>res;
        stack<int>st;
        
        for(int &currIdx: actualIndex){
            if(directions[currIdx]=='R'){
                st.push(currIdx);
            }
            else{
                while((!st.empty()) && healths[currIdx]>0){
                    int topIdx= st.top();
                    st.pop();
                    
                    if(healths[topIdx] > healths[currIdx]){
                        healths[topIdx]-= 1;
                        healths[currIdx]=0;
                        st.push(topIdx);
                    }
                    else if(healths[topIdx] < healths[currIdx]){
                        healths[currIdx] -= 1;
                        healths[topIdx]=0;
                    }
                    else{
                         healths[currIdx] = 0;
                        healths[topIdx]=0;
                    }
                }
            }
        }
         for(int i=0; i<n; i++){
             if(healths[i]>0){
                 res.push_back(healths[i]);
             }
         }      
        return res;
    }
};