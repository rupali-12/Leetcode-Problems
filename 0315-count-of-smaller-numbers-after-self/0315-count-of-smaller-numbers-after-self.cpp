class Solution {
public:
    void merge(vector<pair<int, int>>&v, vector<int>& count, int s, int e, int mid){
        int i=s, j= mid+1;
        vector<pair<int, int>>temp(e-s+1);
        int k=0;
        while(i<=mid && j<=e){
            if(v[i].first<= v[j].first){
                temp[k++]= v[j++];
            }
            else{
                count[v[i].second]+= e -j+1;
               temp[k++]= v[i++];
            }
        }
        while(i<=mid){
           temp[k++]= v[i++];
        }
        while(j<=e){
            temp[k++]= v[j++];
        }
       for(int i=s; i<=e; i++){
           v[i] =temp[i-s];
       }
    }
    void mergeSort(vector<pair<int, int>>&v, vector<int>& count, int s, int e){
       if(s<e){
        int mid= s+(e-s)/2;
        mergeSort(v, count, s, mid);
        mergeSort(v, count, mid+1, e);
        merge(v, count, s, e, mid);
       }
        return;
    }
    vector<int> countSmaller(vector<int>& nums) {
        
       //  // Approach-1> Brute force (Give TLE)
       //  int n= nums.size();
       //  vector<int>count(n, 0);
       // for(int i=0; i<n-1; i++){
       //     for(int j=i+1; j<n;j++){
       //         if(nums[i]>nums[j]){
       //             count[i]++;
       //         }
       //     }
       // }
        // return count;
        
        // Approach-2> 
        
        int n= nums.size();
        vector<pair<int, int>>v(n);
        for(int i=0; i<n; i++){
            pair<int, int>p;
            p.first= nums[i];
            p.second = i;
            v[i]=p;
        }
        vector<int>count(n, 0);
        mergeSort(v, count, 0, n-1);
        return count;
    }
};