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
    ListNode* reverse(ListNode* head){
        if(head==NULL|| head->next==NULL){
            return head;
        }
        ListNode* curr= head;
        ListNode* prev= NULL;
        while(curr!=NULL){
            ListNode*temp= curr->next;
            curr->next= prev;
            prev=curr;
            curr= temp;
        }
        return prev;
    }
//     ListNode* sum(ListNode* l1, ListNode* l2){
//         if(l1==NULL && l2==NULL){
//             return NULL;
//         }
//         if(l1==NULL){
//             return l2;
//         }
//         if(l2==NULL){
//             return l1;
//         }
//         ListNode* ans= new ListNode(-1);
//         ListNode* temp= ans;
//         int carry=0;
//         while(l1!=NULL && l2!=NULL){
//          int sum  = l1->val + l2->val+carry;
//               carry= sum/10;
//                sum%=10;
//             ListNode* newNode= new ListNode(sum);
//             temp->next= newNode;
//             temp= newNode;
//             l1=l1->next;
//             l2= l2->next;
//         }
//         while(l1!=NULL){
//             temp->next= l1;
//             l1= l1->next;
//         }
//          while(l2!=NULL){
//             temp->next= l2;
//             l2= l2->next;
//         }
//         if(carry){
//            ListNode* node =new ListNode(carry);
//             temp->next= node;
//             temp= node;
//         }

//         return ans->next;
//     }
    
    // optimized 
    ListNode* add(ListNode* l1, ListNode* l2){
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
       int carry=0;
        ListNode*ans= new ListNode(-1);
        ListNode* temp= ans;
        while(l1!=NULL || l2!=NULL || carry!=0){
            int val =0;
            if(l1!=NULL){
                  val+= l1->val; 
                l1= l1->next;
            }
             
            if(l2!=NULL){
                  val+= l2->val; 
                l2= l2->next;
            }
            val+=carry;
            carry= val/10;
           ListNode* n= new ListNode(val%10);
            temp->next= n;
            temp=temp->next;
        }
        return ans->next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* revL1 = reverse(l1);
        ListNode* revL2= reverse(l2);
        // ListNode* res= sum(revL1, revL2);
        // Approach-2> 
        ListNode* res = add(revL1, revL2);
        res = reverse(res);
        return res;
    }
};