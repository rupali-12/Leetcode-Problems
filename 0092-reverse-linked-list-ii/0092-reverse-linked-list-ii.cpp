class Solution {
public:
    ListNode* reverseList(ListNode* head, ListNode* &end) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        end = head;
        head= prev;
        return head;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // Move prev to the node just before the left position
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }
        ListNode* before_reverse = prev;
        ListNode* reverse_start = prev->next;

        // Move prev to the right position
        for (int i = left; i < right; ++i) {
            prev = prev->next;
        }

        ListNode* reverse_end = prev->next;
        ListNode* after_reverse = reverse_end->next;
        reverse_end->next = nullptr;

       reverse_start = reverseList(reverse_start, reverse_end);

        before_reverse->next = reverse_start;
        reverse_end->next = after_reverse;

        return dummy->next;
    }
};
