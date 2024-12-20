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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return nullptr;
        ListNode* ptr1 = nullptr;
        ListNode* ptr2 = head;

        while (ptr2 != nullptr) {
            cout << ptr2->val << endl;
            if (ptr2->val == val) {
                if (ptr1 != nullptr) {
                    ptr1->next = ptr2->next;
                    ptr2->next = nullptr;
                    ptr2 = ptr1->next;

                } else {
                    head = head->next;
                    ptr2->next = nullptr;
                    ptr2 = head;
                }
                continue;
            }

            ptr1 = ptr2;
            ptr2 = ptr2->next;
        }

        return head;
    }
};