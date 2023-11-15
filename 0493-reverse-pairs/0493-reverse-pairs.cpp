class Solution {
public:
    int count=0;
    void merge(vector<int>&nums, int s, int e){
        // int mid=(e+s)/2;
        int mid=s+ (e-s)/2;
        int len1= mid-s+1;
        int len2= e-mid;
        
        vector<int>first(len1);
        vector<int>second(len2);
        
        int k=s;
        for(int i=0; i<len1; i++){
            first[i] = nums[k++];
        }
        
        k= mid+1;
        for(int i=0; i<len2; i++){
            second[i] = nums[k++];
        }
        
        int index1=0, index2=0;
        k=s;
        while(index1<len1 && index2<len2){
            if(first[index1]<=second[index2]){
                nums[k++] = first[index1++];
            }
            else{
                nums[k++]= second[index2++];
            }
        }
        while(index1<len1){
            nums[k++] = first[index1++];
        }
        while(index2<len2){
            nums[k++] = second[index2++];
        }
        return;
    }
    void countPairs(vector<int>&nums, int s, int mid, int e){
        int right = mid+1;
        
        for(int i=s; i<=mid; i++){
            while(right<=e && nums[i]>2*(long long)nums[right]){
                right++;
            }
            count+= (right-(mid+1));
        }
    }
    void mergeSort(vector<int>&nums, int s, int e){
        if(s>=e){
            return;
        }
        int mid= s+ (e-s)/2;
        
        mergeSort(nums, s, mid);
        mergeSort(nums, mid+1, e);
        countPairs(nums, s, mid, e);
        merge(nums, s, e);
    }
    int reversePairs(vector<int>& nums) {
        int n= nums.size();
        mergeSort(nums, 0,n-1);
        return count;
    }
};