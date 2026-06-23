class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int size = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            size++;
            temp = temp->next;
        }

        // Delete head
        if (n == size) {
            return head->next;
        }

        int steps = size - n - 1;

        ListNode* curr = head;

        while (steps--) {
            curr = curr->next;
        }

        curr->next = curr->next->next;

        return head;
    }
};