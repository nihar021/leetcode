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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* dummyHead = new ListNode(0);  // Dummy node to hold the result
    ListNode* current = dummyHead;          // Pointer to build the result list
    int carry = 0;                          // Initialize carry to 0
    
    // Traverse both lists until both are exhausted
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;  // Start with carry from the previous operation
        
        if (l1 != nullptr) {  // Add value from l1 if available
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2 != nullptr) {  // Add value from l2 if available
            sum += l2->val;
            l2 = l2->next;
        }
        
        // Update carry for next sum operation
        carry = sum / 10;
        
        // Create a new node with the current digit (sum % 10)
        current->next = new ListNode(sum % 10);
        current = current->next;
    }
    
    // Return the next node of the dummy head as the result (skip the dummy node)
    return dummyHead->next;
    }
};