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
    bool isPalindrome(ListNode* head) {
        // 1.find the middle
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast != NULL && fast->next != NULL){
            slow= slow->next;
            fast = fast->next->next;
        }
        //2.reverse from middle to end
        ListNode* prev= NULL;
        ListNode* curr = slow;
        ListNode* nextNode = slow;

        while(curr != NULL){
            nextNode = curr->next;
            curr->next = prev;
            prev= curr;
            curr = nextNode;
        }

        ListNode* left = head;
        ListNode* right = prev;
        
        //3.compare the value of orginal and rverse part value;

        while(right != NULL){
            if(left->val != right->val){
                return false;
            }
            left=left->next;
            right = right->next;
        }
        return true;
    }
};