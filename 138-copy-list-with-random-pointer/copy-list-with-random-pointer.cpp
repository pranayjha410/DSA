/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        Node* temp = head;

        while (temp != NULL) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next; // store oringial B(not overwirte)

            temp->next = copy;

            // move to next
            temp = copy->next;
        }

        Node* curr = head;
        while (curr != NULL) {
            if (curr->random != NULL) {
                curr->next->random = curr->random->next;
            }

            curr = curr->next->next;
        }

        //spearte A and A`
        curr = head; //A
        Node* copyHead = head->next;    //A'
        while(curr != NULL){
            Node* copy = curr->next;

            curr->next = copy->next; //restore oringinal ll

            if(copy->next != NULL){
                copy->next = copy->next->next;
            }
            curr = curr->next;
        }
        return copyHead;
    }
};