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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m, vector<int>(n, -1));
              
        int id=0;  // 0, 1, 2, 3
        int left=0, right= n-1, top=0, bottom= m-1;
        while(top<=bottom && left<=right){
            if(id==0){    // left to right
                for(int i=left; head!=NULL && i<=right; i++){
                    ans[top][i] = head->val;
                    head= head->next;
                }
                top++;
            }
            else if(id==1){    // top to bottom
                for(int i=top; head!=NULL && i<=bottom; i++){
                    ans[i][right] = head->val;
                    head= head->next;
                }
                right--;
            }
            else if(id==2){    // right to left
                for(int i=right; head!=NULL &&  i>=left; i--){
                    ans[bottom][i] = head->val;
                    head= head->next;
                }
                bottom--;
            }
           else{    // bottom to top
                for(int i=bottom; head!=NULL && i>=top; i--){
                    ans[i][left] = head->val;
                    head= head->next;
                }
                left++;
            }
           
            id= (id+1)%4;
        }
        return ans;
    }
};