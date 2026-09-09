/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;

    struct ListNode *head = NULL;
    struct ListNode *temp = NULL;

    while (l1 != NULL || l2 != NULL || carry) {

        int val1 = (l1 != NULL) ? l1->val : 0;
        int val2 = (l2 != NULL) ? l2->val : 0;

        int sum = val1 + val2 + carry;
        carry = sum / 10;

        struct ListNode *result =(struct ListNode *)malloc(sizeof(struct ListNode));

        result->val = sum % 10;
        result->next = NULL;

        if (head == NULL) {
            head = result;
            temp = result;
        } else {
            temp->next = result;
            temp = result;
        }

        if (l1 != NULL)
            l1 = l1->next;

        if (l2 != NULL)
            l2 = l2->next;
    }

    return head;
}