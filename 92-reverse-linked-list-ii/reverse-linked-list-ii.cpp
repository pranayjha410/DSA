class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (head == NULL || left == right)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Step 1: Reach the node before 'left'
        ListNode* beforeLeft = dummy;
        for (int i = 1; i < left; i++) {
            beforeLeft = beforeLeft->next;
        }

        // Step 2: Start reversing
        ListNode* leftNode = beforeLeft->next;
        ListNode* prev = NULL;
        ListNode* curr = leftNode;

        int count = right - left + 1;

        while (count--) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 3: Reconnect
        beforeLeft->next = prev;
        leftNode->next = curr;

        return dummy->next;
    }
};