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
        auto it2 = it1;
        while(b--) {
            it2 = it2->next;;
        }


        it1->next = list2;

        while(list2->next != nullptr) {
            list2 = list2->next;
        }

        list2->next = it2->next;
        it2->next = nullptr;

        return list1;
    }
};