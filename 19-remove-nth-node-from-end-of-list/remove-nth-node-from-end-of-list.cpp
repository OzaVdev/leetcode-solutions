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

        // FIX 1: Handle an empty list
        if (head == NULL) {
            return head;
        }

        // FIX 2: Count the total number of nodes
        ListNode* temp = head;
        int length = 0;

        while (temp != NULL) {
            length++;
            temp = temp->next;
        }

        // FIX 3: Calculate the target's zero-based index
        int target = length - n;

        // FIX 4: If the target is the head, update head
        if (target == 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // FIX 5: Reach the node immediately before the target
        temp = head;

        for (int i = 0; i < target - 1; i++) {
            temp = temp->next;
        }

        // FIX 6: Skip the target node
        ListNode* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;

        return head;
    }
};