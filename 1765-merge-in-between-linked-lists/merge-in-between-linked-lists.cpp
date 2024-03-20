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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        auto it1 = list1;
        b = b-a+1;
        a--;
        while(a--) {
            it1 = it1->next;;
        }
        cout << it1->val << " ";
        auto it2 = it1;
        while(b--) {
            it2 = it2->next;;
        }

        cout << it2->val << " ";

        it1->next = list2;

        cout << list2->val << endl;
        while(list2->next != nullptr) {
            list2 = list2->next;
        }

        cout << list2->val << endl;

        list2->next = it2->next;
        it2->next = nullptr;

        return list1;
    }
};