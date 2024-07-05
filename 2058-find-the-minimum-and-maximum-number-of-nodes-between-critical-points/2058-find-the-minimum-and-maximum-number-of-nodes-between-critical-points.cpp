/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isCritical(vector<int>&arr, int i){
        if(((arr[i]>arr[i-1]) && (arr[i]>arr[i+1])) || ((arr[i]<arr[i-1]) && (arr[i]<arr[i+1]))) return true;
        return false;
    }
    int findMaxDistance(vector<int>arr, int n){
        int mxAns;
        int firstCritPos = -1, lastCritPos=-1;
        for(int i=1; i<n-1; i++){
            if(isCritical(arr, i)){
                if(firstCritPos==-1) firstCritPos = i+1;
                else lastCritPos = i+1;  // as can update multiple times
            }
        }
        if(lastCritPos==-1){
            mxAns =-1;
        }
        else{
            mxAns = lastCritPos - firstCritPos;
        }
        return mxAns;
    }
    
     int findMinDistance(vector<int>arr, int n){
        int mnAns=-1;
        int firstCritPos = -1, secondCritPos=-1;
        for(int i=1; i<n-1; i++){
            if(isCritical(arr, i)){
                if(firstCritPos==-1) firstCritPos = i+1;
                else{
                    if(secondCritPos==-1){
                        secondCritPos=i+1;
                        mnAns = secondCritPos - firstCritPos;
                    }
                    else{
                        // update both point and mnAns 
                        firstCritPos= secondCritPos;
                        secondCritPos = i+1;
                        mnAns = min(mnAns, (secondCritPos - firstCritPos));
                    }
                }
            }
        }
            return mnAns;
    }
    
    
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>arr;
        ListNode* temp= head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp= temp->next;
        }
        int n= arr.size();
        
        if(n<3) return {-1, -1};
        
        int mxDistance = findMaxDistance(arr, n);
        int mnDistance = findMinDistance(arr, n);
        
        return {mnDistance, mxDistance};
    }
};