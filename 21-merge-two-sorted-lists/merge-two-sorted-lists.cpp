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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Dummy node to simplify the merging process
        ListNode* result = new ListNode();
        ListNode* temp = result;

        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val <= list2->val) {

                // Connect list1's node
                temp->next = list1;
                list1 = list1->next;
            }
            else {

                // Connect list2's node
                temp->next = list2;
                list2 = list2->next;
            }

            // Move temp forward
            temp = temp->next;
        }

        // Attach whichever list is remaining
        if (list1 != nullptr)
            temp->next = list1;
        else
            temp->next = list2;

        // result is the dummy node
        return result->next;
    }
};