class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
     vector<int>arr1, arr2;
     arr1.push_back(nums[0]);
     arr2.push_back(nums[1]);
     for(int i=2; i<nums.size(); i++){
        if(arr1[arr1.size()-1]>arr2[arr2.size()-1]){
            arr1.push_back(nums[i]);
        }
        else{
            arr2.push_back(nums[i]);
        }
     }
     int i=0;
      for(auto a: arr1){
        nums[i] = a;
        i++;
      }
      for(auto a: arr2){
        nums[i] = a;
        i++;
      }
      return nums;
    }
};