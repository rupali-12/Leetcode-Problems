class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n= arr.size();
          int s=0, e=n-1;
    int mid = s+(e-s)/2;
    while(s<=e){
         mid = s+(e-s)/2;
        if(arr[mid]==target){
            return mid;
        }
//         right part is sorted >>search in right part 
        else if(arr[mid]<arr[s]){
            if(target>arr[mid] && target<=arr[n-1]){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        // search in left part
        else{
            if(target<arr[mid] && target>=arr[s]){
                e= mid-1;
            }
            else{
                s= mid+1;
            }
        }
        mid = s+(e-s)/2;
    }
    return -1;
    }
};