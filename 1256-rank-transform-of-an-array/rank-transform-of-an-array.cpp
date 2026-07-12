class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=  arr.size();
        vector<int>temp = arr;
       sort(temp.begin(), temp.end());
      unordered_map<int, int>valueToRank;
      int rank=1;
      for(int i=0; i<n; i++){
        if(!valueToRank[temp[i]]){
            valueToRank[temp[i]] = rank++;
        }
      }

      for(int i=0; i<n; i++){
        arr[i] = valueToRank[arr[i]];
      }
      return arr;
    }
};

