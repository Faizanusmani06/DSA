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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int, int> mp;

        ListNode* ptr1 = nullptr;
        ListNode* ptr2 = head;

        while (ptr2 != nullptr) {

            if (mp.find(ptr2->val) != mp.end()) {
                ptr1->next = ptr2->next;
                ptr2->next = nullptr;
                ptr2 = ptr1->next;
                continue;
            } else {
                mp[ptr2->val] = 1;
            }

            ptr1 = ptr2;
            if (ptr2 != nullptr)
                ptr2 = ptr2->next;
        }

        return head;
    }
};