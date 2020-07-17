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
        ListNode *head = NULL;
        ListNode *(*headmove) = &head;
        int res = 0;
        while (l1 != NULL || l2 != NULL || res != 0){
            if (l1 != NULL){
                res += l1 -> val;
                l1 = l1 -> next;
            }
            
            if (l2 != NULL){
                res += l2 -> val;
                l2 = l2 -> next;
            }
            *headmove = new ListNode(res%10);
            res /= 10;
            headmove = &((*headmove) -> next);
            
        }       
        return head;
        }
};
