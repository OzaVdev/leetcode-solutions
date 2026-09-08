/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* temp = NULL;
    struct ListNode* current_node = head;
    struct ListNode* nextNode;

    while (current_node != NULL) {
        nextNode = current_node->next;  
        current_node->next = temp;      
        temp = current_node;            
        current_node = nextNode;        
    }
    return temp;
}