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
   bool isCritical(vector<int>& arr, int i){
    if((arr[i-1]<arr[i] && arr[i+1]<arr[i]) || (arr[i-1]>arr[i] && arr[i+1]>arr[i])){
        return true;
    }
    return false;
   }

   int findMaxDistance(vector<int>arr, int n){
     int firstCriticalPos =-1, lastCriticalPos=-1;
     int mxDis;
     for(int i=1; i<n-1; i++){
       if(isCritical(arr, i)){
        if(firstCriticalPos ==-1) firstCriticalPos = i+1;  //  index to pos
        else lastCriticalPos =i+1;
       }
     }
     if(lastCriticalPos ==-1) mxDis = -1;
     else mxDis = lastCriticalPos - firstCriticalPos;
     return mxDis;
   }

       int findMinDistance(vector<int>arr, int n){
     int firstCriticalPos =-1, secondCriticalPos=-1;
     int mnDis=-1;
    for(int i=1; i<n-1; i++){
        if(isCritical(arr, i)){
            if(firstCriticalPos == -1)  firstCriticalPos =i+1;
            else {
                if(secondCriticalPos ==-1){
                secondCriticalPos =i+1;
                mnDis = secondCriticalPos - firstCriticalPos;
            }
            else{
                firstCriticalPos = secondCriticalPos;
                secondCriticalPos = i+1;
                mnDis = min(mnDis, (secondCriticalPos - firstCriticalPos));
            }
            }
        }
    }
    return mnDis;
   }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // Approach -1: Brute force
        vector<int>arr;
        ListNode* temp= head;
        while(temp!=NULL){
          arr.push_back(temp->val);
          temp = temp->next;
        } 

        int n = arr.size();
        if(n<3) return {-1, -1};

        int mxDistance = findMaxDistance(arr, n);
        int mnDistance = findMinDistance(arr, n);

        return {mnDistance, mxDistance};
    }
};