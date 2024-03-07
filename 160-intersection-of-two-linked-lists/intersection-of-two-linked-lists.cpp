/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptr1 = headA;
        while(ptr1 != nullptr) {
            ListNode* ptr2 = headB;

            while(ptr2 != nullptr) {
                if(ptr1 == ptr2) return ptr1;
                ptr2 = ptr2->next;
            }

            ptr1 = ptr1->next;
        }

        return nullptr;
    }
};