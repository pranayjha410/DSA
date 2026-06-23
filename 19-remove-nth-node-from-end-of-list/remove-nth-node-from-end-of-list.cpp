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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int size = 0;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }
        int steps = size - n; // steps to reach one before delelte

        // dummy data to handle deletion of first node
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        // for tranvsral current node
        ListNode* curr = dummy;

        while (steps != 0) {
            curr = curr->next;
            steps--;
        }
        // skip(deleted)
        curr->next = curr->next->next;

        return dummy->next; // first node of dummy contains -1;
    }
};