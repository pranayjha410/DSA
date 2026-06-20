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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp = head; // nextNode

        while (curr != NULL) {
            // retain future
            temp = curr->next;

            // reverse
            curr->next = prev;
            prev = curr; // update prev(reverse) head to latest

            // move curr to next
            curr = temp;
        }
        return prev;
    }
};