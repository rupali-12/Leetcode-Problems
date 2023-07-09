#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int candy= candyType.size()/2;
        set<int>s;
        for(int i=0; i<candyType.size(); i++){
            if(s.size()>candy){
                return candy;
            }
            s.insert(candyType[i]);
        }
       return min(static_cast<int>(s.size()), candy);
    }
};