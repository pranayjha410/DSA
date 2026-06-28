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
    void reorderList(ListNode* head) {
        // 1.find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2.reverse from middle to end

        // but separet chain for first hal and second half
        ListNode* second = slow->next;
        slow->next = NULL; // first speareted;
        ListNode* prev = NULL;
        ListNode* curr = second;
        ListNode* nextNode = slow;

        while (curr != NULL) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        ListNode* first = head;
        second = prev;

        while (second != NULL) {
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;
            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        }
    }
};