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
    void reorderList(ListNode* head) {
        vector<int> arr;

        ListNode* ptr = head;
        while(ptr != nullptr) {
            arr.push_back(ptr->val);
            ptr = ptr->next;
        }

        int i = 0, j = arr.size()-1;

        ptr = head;

        while(i < j) {
            ptr->val = arr[i++];
            ptr = ptr->next;
            ptr->val = arr[j--];
            ptr = ptr->next;
        }
        if(i == j && ptr!= nullptr) ptr->val = arr[i];

    }
};