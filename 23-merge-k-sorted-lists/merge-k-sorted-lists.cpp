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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return {};
        priority_queue<int, vector<int>, greater<int>> pq;

        for(ListNode* ptr: lists) {
            if(ptr == nullptr) continue;
            while(ptr != nullptr) {
                pq.push(ptr->val);
                ptr = ptr->next;
            }
        }
        if(pq.size() == 0) return {{}};
        int x = pq.top();
        pq.pop();

        ListNode* ptr = new ListNode(x);
        ListNode* head = ptr;

        while(!pq.empty()) {
            int x = pq.top();
            pq.pop();
            ptr->next = new ListNode(x);
            ptr = ptr -> next;

        }
        return head;
    }
};