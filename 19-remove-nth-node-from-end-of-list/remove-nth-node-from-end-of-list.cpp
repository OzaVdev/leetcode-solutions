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
        if (head == NULL) {
            return head;
        }

        ListNode* temp = head;
        int length = 0;

        while (temp != NULL) {
            length++;
            temp = temp->next;
        }

        int target = length - n;

        if (target == 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        temp = head;

        for (int i = 0; i < target - 1; i++) {
            temp = temp->next;
        }

        ListNode* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;

        return head;
    }
};